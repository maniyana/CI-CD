pipeline {
  options {
      timeout(time: 90, activity: true, unit: 'MINUTES')
  }
  agent none
  stages {
    stage('Build') {
      steps {
        sh 'echo Build'
      }
    }

    stage('test') {
      parallel {
        stage('test') {
          steps {
            sh 'echo test'
          }
        }

        stage('Uni test') {
          steps {
            sh 'echo Unit'
          }
        }

      }
    }

    stage('deploy') {
      steps {
        sh 'echo Deploy'
      }
    }

  }
}
