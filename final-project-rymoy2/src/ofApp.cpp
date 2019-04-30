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
    
    videoData = new unsigned char [camWidth*camHeight*3];
    
    videoTexture.allocate(camWidth,camHeight,GL_RGB);
    
    ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()) {
        finder.update(vidGrabber);
    }
    
//    int filtercase = filter;
    
//    switch(filtercase) {
//
//        case '1':
//            if (vidGrabber.isFrameNew()) {
//                unsigned char* pixels = vidGrabber.getPixels().getData();
//                int bytes_to_examine = camHeight * camWidth * 3;
//
//                for (int i = 0; i < bytes_to_examine; i++) {
//                    videoData[i] = 255 - pixels[i];
//                }
//
//                videoTexture.loadData(videoData, camWidth, camHeight, GL_RGB);
//                videoTexture.draw(0,0);
//            }
//            break;
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
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
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
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

