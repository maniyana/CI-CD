pipeline {
  agent none
  stages {
    stage('Build') {
      parallel {
        stage('Server') {
          agent any
          steps {
            sh '''echo "Building the server code."
            mvn -version
            mkdir -p target
            touch "target/server.war"'''
            stash(name: 'server', includes: '**/*.war')
          }
        }

        stage('Client') {
          steps {
            sh '''echo "Building the client code."
            npm install --save react
            mkdir -p dist
            cat > dist/index.html <<EOF
            hello!
            EOF
            touch "dist/client.js"'''
          }
        }

      }
    }

  }
}
