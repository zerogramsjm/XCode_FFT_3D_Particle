#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //this holds all of our points
    vector<ofVec3f> points;
    //this keeps track of the center of all the points
    ofVec3f center;
    
    //our camera objects for looking at the scene from multiple perspectives
    ofEasyCam camera;
    
    //if usecamera is true, we'll turn on the camera view
    bool camerause;
    
    void addPoint(float x, float y) {
        points.push_back(ofVec2f(x, y));
        speeds.push_back(ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)));
    }
    
    vector <ofVec2f> speeds;
    
    ofVbo vbo;
    
    int mode;
    
    float * fftSmoothed;
    
    ofSoundPlayer         beat;
    
    ofSoundPlayer         beat2;
    
    ofSoundPlayer         beat3;
    
    ofSoundPlayer         beat4;
    
    int nBandsToGet;
    
    int nBandsToGet1;
    
    int nBandsToGet2;
    
    int nBandsToGet3;
    
    int nBandsToGet4;
    
    int ofVec;
    
    int vortex;
    
    //CAMPOSITIONS
    
    int pos1;
    
    int pos2;
    
    int pos3;
    
    //CLOUD
    
    ofQuaternion curRot;
    
    int theColour;
    
    
};
