#include "ofApp.h"
using namespace ofxCv;
using namespace cv;


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    mustache.load("mustache2.png");
    ofBackground(0,0,0);
    
    // the size that the video is grabbed at
    camWidth = 722;
    camHeight = 480;
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(camWidth,camHeight);
    
    vidGrabber.initGrabber(camWidth, camHeight);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()) {
        finder.update(vidGrabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vidGrabber.draw(0,0);
    
    for(int i = 0; i < finder.size(); i++) {
        // returns smoothed rectangle
        ofRectangle object = finder.getObjectSmoothed(i);
        //sets the anchor point the image is drawn around
        mustache.setAnchorPercent(.5, .5);
        // amount I want the object to be scaled to
        float scaleAmount = .85 * object.width / mustache.getWidth();
        
        ofPushMatrix();
        
        ofTranslate(object.x + object.width / 2., object.y + object.height * .70);
        
        ofScale(scaleAmount, scaleAmount);
        
        mustache.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofPopMatrix();
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    //grabs a png of the window using the height and width of the popup window
    if(key == 'x'){
        screenshot.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        screenshot.save("screenshot.png");
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

