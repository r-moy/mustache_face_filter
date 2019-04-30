#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    ofSetupOpenGL(722,480, OF_WINDOW);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new ofApp());
    
}

//how to commit using terminal
//cd /Users/raymondmoy/Desktop/of_v0.10.1_osx_release/apps/myApps/final-project-rymoy2
//git add .
//git commit -m "my message hello"
//git push origin master
