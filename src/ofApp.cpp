#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    mouse_x = mouseX - ofGetWidth() / 2;
    mouse_y = mouseY - ofGetHeight() / 2;
    r = sqrt(pow(mouse_x, 2.0) + pow(mouse_y, 2.0));
    rad = atan(mouse_y / mouse_x);
    if(mouse_x >= 0 && mouse_y >= 0){
        rad = 2.0 * PI - rad;
    } else if(mouse_x >= 0 && mouse_y < 0){
        rad = -rad;
    } else if(mouse_x < 0 && mouse_y >= 0){
        rad = 1.0 * PI - rad;
    } else if(mouse_x < 0 && mouse_y < 0){
        rad = 1.0 * PI - rad;
    }
    hue = ((180 * rad) / PI) * 255 / 360;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    for (int i=1; i < ofGetHeight() / 30; i++) {
        ofLine(0, 30 * i,
               ofGetWidth(), 30 * i);
    }
    for (int i=1; i < ofGetWidth() / 30; i++) {
        ofLine(30 * i, 0,
               30 * i, ofGetHeight());
    }
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
               
    ofSetColor(0, 255, 255);
    ofLine(ofGetWidth() * -1 / 2, mouse_y,
           ofGetWidth() / 2, mouse_y);
    ofLine(mouse_x, ofGetHeight() * -1 / 2,
           mouse_x, ofGetHeight() / 2);
    
    ofColor hsb_color;
    hsb_color.setHsb(hue, 255, 255);
    ofSetColor(hsb_color);
               
    ofFill();
    ofCircle(0, 0, r/5);
    ofNoFill();
    ofCircle(0, 0, r);
    ofLine(0, 0, mouse_x, mouse_y);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
