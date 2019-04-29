#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    // the size that the video is grabbed at
    camWidth = 640;
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
    
    ofPixelsRef pixels = vidGrabber.getPixels();
    
    int filtercase = 1;
    
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
    float videoAlphaValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    
    
    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);
    
    ofPixelsRef pixelsRef = vidGrabber.getPixels();
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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
