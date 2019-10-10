#include "ofApp.h"

  //--------------------------------------------------------------
void ofApp::setup(){
    // clear any leftovers from the memory
    ofClear(ofColor::white);
  
    // VerticalSync helps to prevent tearing but locks the framerate at the screen
    // refresh rate.
    ofSetVerticalSync(false);
    ofSetFrameRate(60);
    //ofSetFrameRate(44100/1024);
    ofSetBackgroundAuto(false);
    ofSetWindowTitle("Listening Machine - Final Project - Shape Fingerprint");
  
    // setup the audio stream
    soundStream.setup(numberOfOutputChannels, numberOfInputChannels, sampleRate, frameSize, numberOfBuffers);
    
    // setup and run mltk
    mltk.setup(frameSize, sampleRate, frameSize/2);
    mltk.run();

   // hpcpSmooth.assign(mltk.getData("HPCP").size(), 0);
    

}

  //--------------------------------------------------------------
void ofApp::update(){
    // This will show us the framerate in the window's title bar
    
//    if(showFps.get()){
//    ofSetWindowTitle("Listening Machine - Week 2 - " + to_string(ofGetFrameRate()));
//    }
    
    // Get data from sound input
    //rms = mltk.getValue("RMS");
    chromagram = mltk.getData("chromagram");
    mfcc_bands = mltk.getData("MFCC.bands");
    //mfcc_coefs = mltk.getData("MFCC.coefs");
    //spectrum = mltk.getData("Spectrum");
    //hpcpUnsmooth = mltk.getData("HPCP");
    
    // this runs the analysis chain that's been declared inside ofxMLTK
    mltk.run();
    
    
}

  //--------------------------------------------------------------
void ofApp::draw(){
    // clear background
    ofBackground(0);
    
//    // draw grid thing
//    for(int i=ofGetWidth()/(mfcc_bands.size()*2); i<ofGetWidth(); i+=ofGetWidth()/mfcc_bands.size()){
//        for(int j=ofGetHeight()/(chromagram.size()*2); j<ofGetHeight(); j+=ofGetHeight()/chromagram.size()){
//            ofSetColor(255);
//
//            // change size based on row
//            //float size = ofMap(chromagram[j], 0, 1, 1, 20);
//            // change offset
//            float offset = ofMap(mfcc_bands[i], 0, .000005, -5, 5);
//            ofDrawEllipse(i, j + offset, 10, 10);
//        }
//    }
    
//    // draw spiral thing
//
//    // translate to the center
//    ofTranslate(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
//
//    for(int i=0; i<mfcc_bands.size(); i++){
//        // get the coords from polar to cartesian
//        float x = r * cos((TWO_PI/mfcc_bands.size() * i) + ang);
//        float y = r * sin((TWO_PI/mfcc_bands.size() * i) + ang);
//
//        // set size
//        float size;
//        if(mfcc_bands[i]<.000005){
//            size = ofMap(mfcc_bands[i], 0, .000005, 1, 30);
//        }
//
//
//        // draw circle
//        ofSetColor(204, 110, 193, 100);
//        ofDrawEllipse(x, y, size, size);
//    }
//
//    r += 1;
//    ang += 0.01;
//    if(r>ofGetHeight()){
//        r = 0;
//    }
    
    
    
    
    // draw radius thing
//    // translate to the center
//    ofTranslate(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
//
//    // draw the rays
//    for(int i=0; i<mfcc_bands.size(); i++){
//        // get the radius
//        float r = ofMap(mfcc_bands[i % 20], 0, .000005, ofGetHeight()/8, ofGetHeight()/4);
//
//        // get the outer coords from polar to cartesian
//        float x = r * cos(TWO_PI/mfcc_bands.size() * i);
//        float y = r * sin(TWO_PI/mfcc_bands.size() * i);
//
//        // get inner coords from polar to cartesian
//        float innerX = ofGetHeight()/4 * sin(TWO_PI/mfcc_bands.size() * i);
//        float innerY = ofGetHeight()/4 * sin(TWO_PI/mfcc_bands.size() * i);
//
//        // draw each ray base on mfcc
//        ofSetColor(244, 110, 193, 100);
//        ofDrawEllipse(x, y, 5, 5);
//        ofDrawLine(innerX, innerY, x, y);
//
//        // get the radius of chromagram circle
//        float chromaR = ofMap(chromagram[i % chromagram.size()], 0, 1, 5, 25);
//
//        // faw an ellipse based on chromagram
//        //ofSetColor(0, chromaAlpha);
//        ofDrawEllipse(ofGetHeight()/4 * cos(TWO_PI/mfcc_bands.size() * i), innerY, chromaR, chromaR);
    //}
}


  //-----
void ofApp::audioIn(ofSoundBuffer &inBuffer){
    inBuffer.getChannel(mltk.leftAudioBuffer, 0);
    inBuffer.getChannel(mltk.rightAudioBuffer, 1);
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
