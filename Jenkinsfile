pipeline {
  agent none
  stages {
    stage('Build') {
      parallel {
        stage('Build') {
          steps {
            sh 'echo Build'
          }
        }

        stage('linux') {
          steps {
            sh 'echo linux'
          }
        }

        stage('PC lint') {
          steps {
            sh 'echo PC lint'
          }
        }

      }
    }

    stage('Sign') {
      parallel {
        stage('Sign') {
          steps {
            sh 'echo sign'
          }
        }

        stage('IAR') {
          steps {
            sh 'echo IAR'
          }
        }

        stage('Unit Testing') {
          steps {
            sh 'echo unit testing'
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
  options {
    timeout(time: 90, activity: true, unit: 'MINUTES')
  }
}