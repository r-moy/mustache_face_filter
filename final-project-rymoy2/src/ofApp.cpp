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
    ofEnableAlphaBlending();
    /////////////////////////////////
    ofBackground(0,0,0);
    
    // the size that the video is grabbed at
    camWidth = 722;
    camHeight = 480;
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(camWidth,camHeight);
    
    output = new unsigned char [camWidth*camHeight];
    
    videoTexture.allocate(camWidth,camHeight,GL_RGB);
    
    ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()) {
        finder.update(vidGrabber);
    }
    
    ofPixelsRef pixels = vidGrabber.getPixels();
    
    int filtercase = filter;
    
    switch(filtercase) {
            
        case 1:
            for (int i = 0; i <(camWidth*camHeight); i++) {
                output[i] = 255 - pixels[i];
            }
            videoTexture.loadData(output,camWidth,camHeight,GL_RGB);
            break;
            
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // change background video alpha value based on the cursor's position
    //float videoAlphaValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    
    //ofSetColor(255,255,255,videoAlphaValue);
    
    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);
    
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        mustache.setAnchorPercent(.5, .5);
        float scaleAmount = .85 * object.width / mustache.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .70);  //.42
        ofScale(scaleAmount, scaleAmount);
        mustache.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofPopMatrix();
    }
    
    //ofPixelsRef pixelsRef = vidGrabber.getPixels();
    
    //ofSetHexColor(0xffffff);
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    filter = key;
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

