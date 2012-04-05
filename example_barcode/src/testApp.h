#pragma once

#include "ofMain.h"

#include "ofxZxing.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofxZxing::Result result;
	ofVideoGrabber cam;
	float lastFound;
	string output;
};
