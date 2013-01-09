#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    comboVals.push_back("one");
    comboVals.push_back("two");
    comboVals.push_back("three");
    
    sliderVal = 0;
    comboVal = 0; //"no combo selected yet";
    enteredText = "no entered text yet";
    // --------------- setup the gui window
    
    GUI.setup("my sample gui", 300, 300);

    GUI.setEventInterface(this);
    
    GUI.addComboBox("combo",  comboVals, &comboVal);
    GUI.addSlider("slider", -2, 2, 0, &sliderVal);
	GUI.addComboBox("combo",  comboVals, &comboVal);
    GUI.addSlider("slider", -2, 2, 0, &sliderVal);
	GUI.addComboBox("combo",  comboVals, &comboVal);
    GUI.addTextEntry("textBox", "please enter text here",  300, &enteredText);
	GUI.addComboBox("combo",  comboVals, &comboVal);
	GUI.addButton("press me button", "press me", &buttonVar);
    
    //  doing this in the setup() means the window pops behind.  I do it in update after 1 full frame, so it pops in front. 
    //  GUI.Show();
    
}

//--------------------------------------------------------------
void testApp::update(){
    if (ofGetFrameNum() == 2) GUI.show();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofDrawBitmapStringHighlight(comboVals[comboVal] , ofPoint(400,30));
    ofDrawBitmapStringHighlight(ofToString(sliderVal), ofPoint(400,60));
    ofDrawBitmapStringHighlight(enteredText, ofPoint(400,90));
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}

//--------------------------------------------------------------
void testApp::guiEvent(nativeWidget & widget){
    cout << "gui event " << widget.name << endl;
}

