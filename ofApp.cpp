//JEVON MAHONEY
//CAMFUCK
//LETS DO THIS
//YOUR NOT MY SUPERVISOR

//30/08/16

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    
    beat.load("sounds/brothel.mp3");
    
    beat2.load("sounds/alex.mp3");
    
    beat3.load("sounds/den.mp3");
    
    beat4.load("sounds/for.mp3");
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    for (int i1 = 0; i1 < 8192; i1++){
        fftSmoothed[i1] = 50;
    }
    
    for (int i2 = 0; i2 < 8192; i2++){
        fftSmoothed[i2] = 100;
    }
    
    for (int i3 = 0; i3 < 8192; i3++){
        fftSmoothed[i3] = 150;
    }
    
    for (int i4 = 0; i4 < 8192; i4++){
        fftSmoothed[i4] = 200;
    }
    
    nBandsToGet = 1;
    
    nBandsToGet1 = 11;
    
    nBandsToGet2 =  25;
    
    nBandsToGet3 =  35;
    
    nBandsToGet4 =  2;
    
    ofSetFrameRate(180);
    ofSetVerticalSync(true);
    ofBackground(255);
    
    camerause = false;
    
    //CAM POSITIONS
    
    pos1 = ofGetHeight()/2;
    
    pos2 = ofGetWidth()/2;
    
    pos3 = 400;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    theColour = 255,0,0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    for (int i1 = 0;i1 < nBandsToGet; i1++){
        
        for (int i2 = 10;i2 < nBandsToGet1; i2++){
            
            for (int i3 = 24;i3 < nBandsToGet2; i3++){
                
                for (int i4 = 1;i4 < nBandsToGet4; i4++){
                    
                    for (int i=0; i<30; i++) {
                        
                        if (fftSmoothed[i] >= 0.1) {
                            addPoint(0, 0);
                        }
                        
                    }
                    
                    ofVec3f sumOfAllPoints(0,0,0);
                    for(unsigned int i = 0; i < points.size(); i++){
                        
                        points[i].z -= fftSmoothed[i1] * 5;
                        
                        sumOfAllPoints += points[i];
                        
                        center = sumOfAllPoints / points.size();
                        
                        //WE'LL CONTINUE WORK ON THIS SPECIFIC ALGORITHM... AT SOMEPOINT
                        //if (points[i].z <= -50) {
                        //points[i].z += fftSmoothed[i1] * 3;
                        //}
                        
                    }
                    
                    ////
                    
                    for (unsigned int i=0; i<points.size(); i++) {
                        
                        //DOWN BY VOLUME
                        
                        speeds[i].y += fftSmoothed[i4] * 5;
                        
                        //UP BY MID
                        
                        speeds[i].y -= fftSmoothed[i1] * 5;
                        
                        //RIGHT BY TREBLE
                        
                        speeds[i].x -= fftSmoothed[i2] * 5;
                        
                        //LEFT BY SNARE
                        
                        speeds[i].x += fftSmoothed[i3] * 5;
                        
                        //------
                        
                        points[i]   += speeds[i];
                        
                        speeds[i]   *= 0.09;
                        
                        ofVec2f mouseVec = ofVec2f(0,
                                                   0)
                        - points[i];
                        
                        
                        //  if(mouseVec.length() < INFINITY ) {
                        //    mouseVec.normalize();
                        //      speeds[i] -= mouseVec * 3 ;
                        
                    }
                    
                }
                
                float * val = ofSoundGetSpectrum(nBandsToGet);
                for (int i = 0;i < nBandsToGet; i++){
                    
                    fftSmoothed[i] *= 0.96f;
                    
                    if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
                    
                }
                
                float * val1 = ofSoundGetSpectrum(nBandsToGet1);
                for (int i = 0;i < nBandsToGet1; i++){
                    
                    fftSmoothed[i] *= 0.96f;
                    
                    if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val1[i];
                    
                }
                
                float * val2 = ofSoundGetSpectrum(nBandsToGet2);
                for (int i = 0;i < nBandsToGet2; i++){
                    
                    fftSmoothed[i] *= 0.96f;
                    
                    if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val2[i];
                    
                }
                
                float * val3 = ofSoundGetSpectrum(nBandsToGet3);
                for (int i = 0;i < nBandsToGet3; i++){
                    
                    fftSmoothed[i] *= 0.96f;
                    
                    if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val3[i];
                    
                }
                
                float * val4 = ofSoundGetSpectrum(nBandsToGet4);
                for (int i = 0;i < nBandsToGet4; i++){
                    
                    fftSmoothed[i] *= 0.96f;
                    
                    if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val4[i];
                    
                }
                
            }
            
        }
        
    }
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    //camera.setPosition(0, 0, -3000);
    
    //camera.enableMouseMiddleButton();
    
    for (int i1 = 0;i1 < nBandsToGet; i1++){
        
        for (int i2 = 10;i2 < nBandsToGet1; i2++){
            
            //ofSetBackgroundColor(fftSmoothed[i1] * 300, fftSmoothed[i1] * 300, fftSmoothed[i1] * 300);
            
            ofSetBackgroundColor(0);
            
            ofSetColor(255,0,0);
            
            ofMesh mesh;
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
            for(unsigned int i = 1; i < points.size(); i++){
                
                glPointSize(1);
                
                ofVec3f thisPoint = points[i-1];
                ofVec3f nextPoint = points[i];
                
                ofVec3f direction = (nextPoint - thisPoint);
                
                float distance = direction.length();
                
                ofVec3f unitDirection = direction.getNormalized();
                
                ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
                ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
                
                //float thickness = ofMap(distance, 0, 2 + fftSmoothed[i1] * 35, 2 + fftSmoothed[i2] * 250, 2, true);
                
                float thickness = (1);
                
                ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
                ofVec3f rightPoint = thisPoint+toTheRight*thickness;
                
                mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
                mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
                
            }
            
            if(camerause){
                camera.begin();
            }
            
            mesh.draw();
            
            //ofDrawGrid(1000, 200, false, false, true, true);
            
            // -==-=-===-=-=-=-===-=-
            
            //ofDrawBox(ofRandom(-1000,1000), (-1000,1000), (-1000,1000), 5, 5, 5);
            
        }
        
    }
    
    camera.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case'f':
            ofToggleFullscreen();
            break;
    }
    
    if( key == '1')
    {
        beat.play();
    }
    
    if( key == '2')
    {
        beat2.play();
    }
    
    if( key == '3')
    {
        beat3.play();
    }
    
    if( key == '4')
    {
        beat4.play();
    }
    
    if( key == 'x')
    {
        beat.stop();
        beat2.stop();
        beat3.stop();
        beat4.stop();
        
    }
    
    if(key == 'n') {
        points.clear();
        speeds.clear();
    }
    
    if( key == 'o')
    {
        camerause=true;
    }
    
    if( key == 'p')
    {
        camerause=false;
    }
    
    //CAM POSITIONS
    
    if( key == 'x')
    {
        ofDrawGrid(1000, 200, false, false, true, true);
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
