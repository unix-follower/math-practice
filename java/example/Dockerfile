FROM openjdk:17-alpine3.14

WORKDIR /opt/app
COPY target/example.jar .
COPY target/lib lib

CMD  /opt/openjdk-17/bin/java -jar example.jar
