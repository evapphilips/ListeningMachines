#include "ofApp.h"

  //--------------------------------------------------------------
void ofApp::setup(){
    // clear any leftovers from the memory
    ofClear(ofColor::white);
  
    // VerticalSync helps to prevent tearing but locks the framerate at the screen
    // refresh rate.
    ofSetVerticalSync(false);
    ofSetFrameRate(10);
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
    
    // variable
    int size = 40;
    bool takeGrab = false;
    //ofLog() << "console: " << nums[0];

    
    for(int i=0; i<chromagram.size(); i++){
        //ofSetColor(255, 200);
        if(chromagram[i] == 1){
            if(i == 0){
                ofSetColor(244, 110, 193, 100);
                ofDrawEllipse(xPos, yPos, size, size);
                ofSetColor(204, 110, 193, 100);
                ofDrawEllipse(xPos, yPos, 3*size/4, 3*size/4);
                ofSetColor(112, 140, 193, 100);
                ofDrawEllipse(xPos, yPos, size/2, size/2);
                ofSetColor(113, 204, 216, 100);
                ofDrawEllipse(xPos, yPos, size/4, size/4);
            }else if(i == 1){
                ofSetColor(215, 249, 241, 100);
                ofDrawRectangle(xPos, yPos, size/2, size);
            }else if(i == 2){
                ofSetColor(112, 140, 193);
                ofDrawRectangle(xPos, yPos, size/4, size/2);
                ofDrawEllipse(xPos + size/8, yPos, size/4, size/4);
                ofDrawEllipse(xPos + size/8, yPos + size/2, size/4, size/4);
            }else if(i == 3){
                ofSetColor(113, 204, 216, 100);
                ofDrawEllipse(xPos, yPos, size/2, size/2);
            }else if(i == 4){
                ofSetColor(244, 110, 193, 100);
                ofDrawEllipse(xPos, yPos, 2*size, 2*size);
                ofSetColor(204, 110, 193, 100);
                ofDrawEllipse(xPos, yPos, 2*3*size/4, 2*3*size/4);
                ofSetColor(112, 140, 193, 100);
                ofDrawEllipse(xPos, yPos, 2*size/2, 2*size/2);
                ofSetColor(113, 204, 216, 100);
                ofDrawEllipse(xPos, yPos, 2*size/4, 2*size/4);
            }else if(i == 5){
                ofSetColor(244, 110, 193, 100);
                ofDrawRectangle(xPos, yPos, size/8, size/8);
            }else if(i == 6){
               ofSetColor(204, 110, 193, 100);
               ofDrawRectangle(xPos, yPos, size, size/6);
            }else if(i == 7){
                ofSetColor(113, 204, 216);
                ofDrawRectangle(xPos, yPos, size/2, size);
                ofDrawEllipse(xPos + size/4, yPos, size/2, size/2);
                ofDrawEllipse(xPos + size/4, yPos + size, size/2, size/2);
            }else if(i == 8){
                ofSetColor(244, 110, 193, 100);
                ofDrawEllipse(xPos, yPos, size/6, size/6);
            }else if(i == 9){
                ofSetColor(112, 140, 193, 100);
                ofDrawRectangle(xPos, yPos, size/4, size/2);
            }else if(i == 10){
                ofSetColor(113, 204, 216, 100);
                ofNoFill();
                ofDrawRectangle(xPos, yPos, size, size);
                ofFill();
            }else if(i == 11){
                ofSetColor(204, 110, 193, 100);
                ofDrawRectangle(xPos, yPos, 2*size, size/6);
            }
        
//        ofTranslate(xPos, yPos);
//        ofRotateDeg(ofMap(i, 0, 11, 0, 360));
//            ofDrawLine(0, 0, 0 + size, 0);
//        ofRotateDeg(-ofMap(i, 0, 11, 0, 360));
//        ofTranslate(-xPos, -yPos);
        
       }
        
        
        for(int i=0; i<hpcpUnsmooth.size(); i++){
            if(hpcpUnsmooth[i] == 1){
                ofSetColor(255);
                ofSetLineWidth(2.0f);
                if(i == 4){
                    ofDrawLine(xPos, yPos, xPos + size, yPos + size);
                    ofDrawLine(xPos + size, yPos + size, xPos + 2*size, yPos);
                }else if(i == 8){
                    ofDrawLine(xPos, yPos, xPos + 2*size, yPos + 2*size);
                    ofDrawLine(xPos + 2*size, yPos + 2*size, xPos + 4*size, yPos);
                }
            }
        }
    }
    
    // update x and y positions
    if(yPos<ofGetHeight()){
        xPos += size;
           if(xPos > ofGetWidth()){
               yPos += size;
               xPos = 0;
           }
    }else{
        takeGrab = true;
    }

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
