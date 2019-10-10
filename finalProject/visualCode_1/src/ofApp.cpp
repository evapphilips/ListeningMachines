#include "ofApp.h"

  //--------------------------------------------------------------
void ofApp::setup(){
    // clear any leftovers from the memory
    ofClear(ofColor::black);
  
    // VerticalSync helps to prevent tearing but locks the framerate at the screen
    // refresh rate.
    ofSetVerticalSync(false);
    ofSetFrameRate(10);
    //ofSetFrameRate(44100/1024);
    ofSetBackgroundAuto(false);
    ofSetWindowTitle("Listening Machine - Final Project - Record Fingerprint");
  
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
    //mfcc_bands = mltk.getData("MFCC.bands");
    //mfcc_coefs = mltk.getData("MFCC.coefs");
    //spectrum = mltk.getData("Spectrum");
    hpcpUnsmooth = mltk.getData("HPCP");
    
    // this runs the analysis chain that's been declared inside ofxMLTK
    mltk.run();
    
    
}

  //--------------------------------------------------------------
void ofApp::draw(){
    // clear background
    //ofBackground(0);
    
    // variables
    int wLow = 0;
    int wHigh = 25;
    bool takeGrab = false;

    // translate to the center
    ofTranslate(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    
    if(theta < TWO_PI){
    for(int i=0; i<chromagram.size(); i++){
        if(chromagram[i]>.7){
        // convert to cartesian
        float x = ofMap(i, 0, chromagram.size(), ofGetHeight()/8, ofGetHeight()/2) * cos(theta);
        float y = ofMap(i, 0, chromagram.size(), ofGetHeight()/8, ofGetHeight()/2) * sin(theta);
        
        // set color
        //ofSetColor(graphColor);
        ofSetColor(4, 196, 217, ofMap(hpcpUnsmooth[i], 0, 1, 50, 0));
        
        // draw circle
            //ofNoFill();
        ofDrawEllipse(x, y, ofMap(chromagram[i], .7, 1, wLow, wHigh), ofMap(chromagram[i], .7, 1, wLow, wHigh));
            
        }
        
    }
    theta += TWO_PI/1800;
    }else{
        takeGrab = true;
    }
    
    // translate back
    ofTranslate(ofPoint(-ofGetWidth()/2, -ofGetHeight()/2));
    
    // save screen grab
    if(takeGrab){
        img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        img.save("screenshot.jpg");
        takeGrab = false;
    }
        
  
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
