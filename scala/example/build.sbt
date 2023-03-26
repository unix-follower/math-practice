import sbt.Keys.libraryDependencies

val scala3Version = "3.1.0"
val slf4jVersion = "1.7.32"
val logbackVersion = "1.2.7"
val jmhVersion = "1.33"

lazy val root = project
    .in(file("."))
    .settings(
        name := "example",
        version := "0.1.0-SNAPSHOT",

        scalaVersion := scala3Version,

        libraryDependencies ++= Seq(
            "org.slf4j" % "slf4j-api" % slf4jVersion,
            "ch.qos.logback" % "logback-core" % logbackVersion,
            "ch.qos.logback" % "logback-classic" % logbackVersion,

            "net.aichler" % "jupiter-interface" % JupiterKeys.jupiterVersion.value % Test,
            "org.junit.jupiter" % "junit-jupiter-engine" % "5.8.2" % Test
        ),
    )
