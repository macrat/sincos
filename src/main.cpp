#include <memory>

#include <ofMain.h>

#include "ofApp.h"
#include "ofAppTwo.h"


int main(){
	ofGLFWWindowSettings settings;
	settings.width = 640;
	settings.height = 480;

	ofRunApp(ofCreateWindow(settings), std::shared_ptr<ofApp>(new ofApp()));
	ofRunApp(ofCreateWindow(settings), std::shared_ptr<ofAppTwo>(new ofAppTwo()));

	ofRunMainLoop();
}
