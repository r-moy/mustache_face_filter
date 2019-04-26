#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    // the size that the video is grabbed at
    camWidth = 640;
    camHeight = 480;
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(camWidth,camHeight);
    
    ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // change background video alpha value based on the cursor's x-position
    float videoAlphaValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    
    // set a white fill color with the alpha generated above
    ofSetColor(255,255,255,videoAlphaValue);
    
    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);
    
    ofPixelsRef pixelsRef = vidGrabber.getPixels();
    
    ofSetHexColor(0xffffff);
    
    for (int i = 0; i < camWidth; i+= 7){
        for (int j = 0; j < camHeight; j+= 9){
            // get the pixel and its lightness (lightness is the average of its RGB values)
            float lightness = pixelsRef.getColor(i,j).getLightness();
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    if (key == 's' || key == 'S'){
        vidGrabber.videoSettings();
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
