#include <functional>

#include <ofApp.h>


void ofApp::setup() {
	ofBackground(0, 0, 0);
}


void drawFunction(std::function<float(float)> func) {
	for(int x=0; x<ofGetWidth(); x++){
		ofDrawRectangle(x, func(x), 1, 1);
	}
}


float getCircleR() {
	return ofGetWidth() / (2*PI) / 3;
}


float sinLine(const float x) {
	return sin(x / getCircleR()) * getCircleR() + ofGetHeight()/4.0;
}


float cosLine(const float x) {
	return cos(x / getCircleR()) * getCircleR() + ofGetHeight()*3/4.0;
}


void ofApp::draw() {
	{
		ofNoFill();
		ofPushMatrix();
		ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
		ofScale(min(ofGetHeight(), ofGetWidth()) / 3.0);

		ofSetColor(255, 255, 255);
		ofDrawCircle(0, 0, 1.0);

		const float x = cos(mouseX/getCircleR()); 
		const float y = sin(mouseX/getCircleR());

		ofSetColor(255, 0, 0);
		ofDrawLine(0, 0, 0, y);

		ofSetColor(0, 255, 0);
		ofDrawLine(0, 0, x, 0);

		ofSetColor(255, 255, 0);
		ofDrawLine(0, 0, x, y);

		ofSetColor(128, 128, 128);
		ofDrawLine(x, 0, x, y);
		ofDrawLine(0, y, x, y);

		ofSetColor(255, 255, 255);
		ofDrawCircle(x, y, 0.05);

		ofPopMatrix();
		ofFill();
	}

	{
		ofSetColor(128, 128, 128);
		ofDrawLine(0, ofGetHeight()/4.0, ofGetWidth(), ofGetHeight()/4.0);
		ofDrawLine(0, ofGetHeight()*3/4.0, ofGetWidth(), ofGetHeight()*3/4.0);

		ofSetColor(255, 255, 255);
		drawFunction(sinLine);
		drawFunction(cosLine);
	}

	{
		ofDrawLine(mouseX, 0, mouseX, ofGetHeight());

		ofSetColor(255, 0, 0);
		ofDrawCircle(mouseX, sinLine(mouseX), getCircleR()/6.0);
		ofDrawLine(mouseX, ofGetHeight()/4.0, mouseX, sinLine(mouseX));

		ofSetColor(0, 255, 0);
		ofDrawCircle(mouseX, cosLine(mouseX), getCircleR()/6.0);
		ofDrawLine(mouseX, ofGetHeight()*3/4.0, mouseX, cosLine(mouseX));
	}
}
