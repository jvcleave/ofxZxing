#include "testApp.h"

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	output = "NO RESULT";
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) 
	{
		ofxZxing::Result curResult = ofxZxing::decodeBarCode(cam.getPixelsRef());
		float curTime = ofGetElapsedTimef();
		if(curResult.getFound()) { // only update if we found something, avoid flickering
			result = curResult;
			output = result.getText();
			lastFound = curTime;
		} else if(curTime - lastFound > 1) {  // if we haven't found anything after a second
			result = curResult; // then update anyway
			output = "NO RESULT";
		}
	}
	
	ofSetWindowTitle(output);
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	if(result.getFound()) 
	{
		
		float rotation = result.getRotation();
		ofVec2f position = result.getScreenPosition();
		vector<ofVec2f> &points = result.getPoints();
		ofDrawBitmapStringHighlight(result.getText(), points[0]);
		
	}
}
