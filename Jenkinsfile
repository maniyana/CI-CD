pipeline {
  agent any
  stages {
    stage('IAR') {
      parallel {
        stage('IAR') {
          steps {
            sh 'Build IAR'
          }
        }

        stage('linux') {
          steps {
            sh 'Build Linux'
          }
        }

        stage('PC lint') {
          steps {
            sh 'Build PC lint'
          }
        }

      }
    }

    stage('Flash') {
      parallel {
        stage('Flash') {
          steps {
            sh 'Build Flash'
          }
        }

        stage('Positive') {
          steps {
            echo 'Print response'
          }
        }

        stage('Unit') {
          steps {
            sh 'Build Unit'
          }
        }

      }
    }

    stage('Tech') {
      steps {
        sh 'Build Tech'
      }
    }

  }
}