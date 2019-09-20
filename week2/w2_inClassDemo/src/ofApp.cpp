#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // clear any leftovers from the memory
    ofClear(ofColor::black);
    
    // VerticalSync helps to prevent tearing but locks the framerate at the screen
    // refresh rate.
    ofSetVerticalSync(false);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofSetWindowTitle("Listening Machine - Week 2 - ");
    
    // setup the audio stream
    soundStream.setup(numberOfOutputChannels, numberOfInputChannels, sampleRate, frameSize, numberOfBuffers);
    
    mltk.setup(frameSize, sampleRate, frameSize/2);
    mltk.run();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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

void ofApp::audioIn(ofSoundBuffer &inBuffer){
    inBuffer.getChannel(mltk.leftAudioBuffer, 0);
    inBuffer.getChannel(mltk.rightAudioBuffer, 1);
}
