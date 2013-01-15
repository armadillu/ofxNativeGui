
#pragma once

#include "ofMain.h"

#include "ofxNativeGui.h"



class ofxNativeGuiAutoLayout : public ofxNativeGui {
    
public: 
    

	void setup(string name, int windowWidth_ = 300, int canvasH = 2500, int padding_ = 5){

		padding = padding_;
		totalH = 0;
		margin = 20;
		labelW = 95;
		windowW = windowWidth_;

		ofxNativeGui::setup( ofRectangle(ofGetWindowPositionX() + ofGetWindowWidth(), ofGetWindowPositionY(), windowW, canvasH), name );

	}

	void addSlider(string name, float minValue, float maxValue, float startValue, float * variable){
		*variable = startValue;
		ofRectangle r;
		r.x = margin;
		r.height = getHeightForWidget(SLIDER);
		r.y = margin + padding + totalH ;
		r.width = windowW - 2* margin - labelW;

		ofxNativeGui::addSlider(name, r, minValue, maxValue, startValue, variable);
		totalH += r.height + padding;
	}


	void addComboBox(string name, vector < string > options, int * variable){
		ofRectangle r;
		r.x = margin;
		r.y = margin + padding + totalH;
		r.width = windowW - 2* margin;
		r.height = getHeightForWidget(COMBO_BOX);
		ofxNativeGui::addComboBox(name, r, options, variable);
		totalH += r.height + padding;
	}

	void addButton(string name, string buttonText, bool * variable){
		ofRectangle r;
		r.x = margin;
		r.y = margin + padding + totalH;
		r.width = windowW - 2* margin;
		r.height = getHeightForWidget(COMBO_BOX);
		ofxNativeGui::addButton(name, buttonText, r, variable);
		totalH += r.height + padding;
	}


	void addTextEntry(string name, string defaultText, int height, string * variable){
		ofRectangle r;
		r.x = margin;
		r.y = margin + padding + totalH;
		r.width = windowW - 2* margin;
		r.height = height;
		ofxNativeGui::addTextEntry(name, defaultText, r, variable);
		totalH += r.height + padding;
	}
private:

	enum WidgetTypes{SLIDER, COMBO_BOX, TEXT_ENTRY};

	int getHeightForWidget(WidgetTypes w){
		switch (w) {
			case SLIDER: return 22;
			case COMBO_BOX: return 30;
			case TEXT_ENTRY: return 22;
			default: return 25;
		}
	}
	


	int margin;
	int padding;
	int totalH;
	int windowW;
	int labelW; 

    
};