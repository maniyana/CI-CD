pipeline {
  options {
      timeout(time: 90, activity: true, unit: 'MINUTES')
  }
  agent none
  stages {
    stage('Parallel Wrapper') {
      parallel {
        stage('Build/Test/Deploy Wrapper') {
          agent none
          stages {
            stage('Generate Build Files And Build Image') {
              agent {
                label "tasking"
              }
           
             
              post {
                always {
                  cleanWs()
                }
              }
            }
            // We do unit test before live test so that live tests won't be crowded
            // stage('Unit Test') {
            // }
            stage('Sign & Deploy') {
              agent {
                label "linux"
              }
              
              
              post {
                always {
                  cleanWs()
                }
              }
            }
            stage('Live Test with cleanup') {
              agent none
           
        }

        // This stage runs on the PC with the PCLint license
        stage('Perform Static Analysis, Unit Tests, and Code Coverage') {
          agent {
            label "linux"
          }
          stages {
            stage('Run PCLint Plus on Source Code') {
              
              
            }
            stage('Run Unit Tests') {
              steps {
                sh '''
                   mkdir -p build && cd build
                   cmake -GNinja -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
                   cmake --build .
                   ctest --output-on-failure'''
              }
            }
            stage('Perform Code Coverage Analysis') {
              
            }
          }
          post {
            // Remove the workspace after every build
            always {
              cleanWs()
            }
          }
        }
      }
    }
  }
} // pipeline
}
