import java.nio.charset.StandardCharsets

group = "org.example"
version = "0.0.1-SNAPSHOT"
java.sourceCompatibility = JavaVersion.VERSION_17

plugins {
    java
    jacoco
    id("me.champeau.jmh") version "0.6.6"
}

apply(plugin = "me.champeau.jmh")

repositories {
    mavenCentral()
}

private object V {
    const val JMH_VERSION = "1.33"
}

val logbackVersion = "1.2.7"
val jmhVersion = V.JMH_VERSION

dependencies {
    implementation("org.slf4j:slf4j-api:1.7.32")
    implementation("ch.qos.logback:logback-classic:$logbackVersion")
    implementation("ch.qos.logback:logback-core:$logbackVersion")
    implementation("org.apache.commons:commons-math3:3.6.1")
    implementation("org.apache.commons:commons-lang3:3.12.0")

    testImplementation("org.junit.jupiter:junit-jupiter:5.8.2")

    jmhImplementation("org.openjdk.jmh:jmh-core:$jmhVersion")
    jmhImplementation("org.openjdk.jmh:jmh-generator-annprocess:$jmhVersion")
}

tasks.withType<JavaCompile> {
    options.encoding = StandardCharsets.UTF_8.name()
}

tasks.withType<Test> {
    useJUnitPlatform {
        val junitTags = System.getProperty("junit-tags")
        if (junitTags != null && junitTags.isNotBlank()) {
            includeTags(junitTags)
        }

        val junitExcludeTags = System.getProperty("junit-exclude-tags")
        if (junitExcludeTags != null && junitExcludeTags.isNotBlank()) {
            excludeTags(junitExcludeTags)
        }
    }
    finalizedBy(tasks.jacocoTestReport)
}

tasks.jar {
    archiveFileName.set("${project.name}.jar")

    manifest {
        attributes(
            mapOf(
                "Build-Jdk-Spec" to java.sourceCompatibility,
                "Implementation-Title" to project.name,
                "Implementation-Version" to project.version,
                "Main-Class" to "org.example.math.ExampleApp",
                "Class-Path" to configurations.runtimeClasspath.get()
                    .files
                    .joinToString(" ") { "lib/" + it.name },
            )
        )
    }

    finalizedBy("copyDependencies")
}

tasks.register<Copy>("copyDependencies") {
    from(configurations.runtimeClasspath).into("$buildDir/libs/lib")
}

tasks.build {
    finalizedBy("sourceJar")
}

tasks.register<Jar>("sourceJar") {
    dependsOn("classes")
    archiveFileName.set("${project.name}-sources.jar")
    from(sourceSets.main.get().allSource)
}

jmh {
    jmhVersion.set(V.JMH_VERSION)
    fork.set(1)
    threads.set(2)
    warmup.set("1s")
    warmupIterations.set(2)
    iterations.set(2)
    timeOnIteration.set("1s")
    timeUnit.set("ms")
    benchmarkMode.set(setOf("all"))
}
