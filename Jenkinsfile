pipeline {
  options {
    timeout(time: 90, activity: true, unit: 'MINUTES')
  }
  agent none
  stages {
    stage('IAR') {
      parallel {
        stage('IAR') {
          steps {
            sh 'echo Build'
          }
        }

        stage('linux') {
          steps {
            sh 'echo Linux'
          }
        }

        stage('PC lint') {
          steps {
            sh 'echo PC lint'
          }
        }

      }
    }

    stage('flash') {
      parallel {
        stage('flash') {
          steps {
            sh 'echo test'
          }
        }

        stage('flash test') {
          steps {
            sh 'echo flash'
          }
        }

        stage('Unit Testing') {
          steps {
            sh 'echo Unit testing'
          }
        }

      }
    }

    stage('deploy') {
      parallel {
        stage('deploy') {
          steps {
            sh 'echo Deploy'
          }
        }

        stage('positive') {
          steps {
            sh 'echo positive'
          }
        }

      }
    }

  }
  
}
