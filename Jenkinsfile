pipeline {
    agent any
    tools {
        maven '/usr/share/maven'
        jdk '/usr/lib/jvm/java-8-openjdk-amd64/jre'
    }
    stages {
        stage("Tools initialization") {
            steps {
                sh "mvn --version"
                sh "java -version"
            }
        }
        stage("Checkout Code") {
            steps {
                checkout scm
            }
        }
        stage("Check Code Health") {
            when {
                not {
                    anyOf {
                        branch 'master';
                        branch 'new3-jenkins'
                    }
                }
           }
           steps {
               sh "mvn clean compile"
            }
        }
        stage("Run Test cases") {
            when {
                branch 'new3-jenkins';
            }
           steps {
               sh "mvn clean test"
            }
        }
        stage("Check Code coverage") {
            when {
                branch 'new3-jenkins'
            }
            steps {
               jacoco(
                    execPattern: '**/target/**.exec',
                    classPattern: '**/target/classes',
                    sourcePattern: '**/src',
                    inclusionPattern: 'com/iamvickyav/**',
                    changeBuildStatus: true,
                    minimumInstructionCoverage: '30',
                    maximumInstructionCoverage: '80')
           }
        }
        stage("Build & Deploy Code") {
            when {
                branch 'master'
            }
            steps {
                sh "mvn tomcat7:deploy"
            }
        }
    }
 }
