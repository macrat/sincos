#pragma once

#include <ofMain.h>


float getCircleRTwo() {
	return min(ofGetWidth(), ofGetHeight()) / (2*PI) / 2;
}


float sinLineTwo(const float x) {
	return sin(x / getCircleRTwo()) * getCircleRTwo() + ofGetHeight()/2.0;
}


float cosLineTwo(const float y) {
	return cos(y / getCircleRTwo()) * getCircleRTwo() + ofGetWidth()/2.0;
}


class ofAppTwo : public ofBaseApp {
public:
	void setup() override {
		ofBackground(0, 0, 0);
	}
	void draw() override {
		{
			ofSetColor(128, 128, 128);
			ofDrawLine(0, ofGetHeight()/2.0, ofGetWidth(), ofGetHeight()/2.0);
			ofDrawLine(ofGetWidth()/2.0, 0, ofGetWidth()/2.0, ofGetHeight());

			ofSetColor(255, 160, 160);
			for(int x=0; x<ofGetWidth(); x++){
				ofDrawBox(x, sinLineTwo(x), 1, 1);
			}

			ofSetColor(160, 255, 160);
			for(int y=0; y<ofGetHeight(); y++){
				ofDrawBox(cosLineTwo(y), y, 1, 1);
			}
		}

		{
			ofNoFill();
			ofPushMatrix();
			ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
			ofScale(getCircleRTwo());

			ofSetColor(255, 255, 255);
			ofDrawCircle(0, 0, 1.0);

			const float x = cos(mouseX/getCircleRTwo());
			const float y = sin(mouseX/getCircleRTwo());

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
			const float x = ofGetWidth()/2.0 + cos(mouseX/getCircleRTwo()) * getCircleRTwo();
			const float y = ofGetHeight()/2.0 + sin(mouseX/getCircleRTwo()) * getCircleRTwo();

			ofSetColor(255, 0, 0);
			ofDrawCircle(mouseX, sinLineTwo(mouseX), getCircleRTwo()/6.0);
			ofDrawLine(mouseX, sinLineTwo(mouseX), x, y);

			ofSetColor(0, 255, 0);
			ofDrawCircle(cosLineTwo(mouseX), mouseX, getCircleRTwo()/6.0);
			ofDrawLine(cosLineTwo(mouseX), mouseX, x, y);
		}
	}
};
