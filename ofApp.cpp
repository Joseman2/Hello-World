#include "ofApp.h"

ofApp::ofApp()
    :m_MainLevel("settings.xml",&m_Inputhandler)
{

}

ofApp::~ofApp()
{

}

//--------------------------------------------------------------
void ofApp::setup()
{
    //ofxXmlSettings settings;
    //settings.setValue("MainLevel:Model", "Lobby/Lobby4.3ds");
    //settings.setValue("MainLevel:Start X", 0.0);
    //settings.setValue("MainLevel:Start Y", 0.0);
    //settings.setValue("MainLevel:Start Z", 0.0);
    //settings.saveFile("settings.xml");              //puts settings.xml file in the bin/data folder}
    try
    {
        m_MainLevel.setup();
    }
    catch (std::exception exception)
    {
        int test(0);
        exit();
    }
}
//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_MainLevel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    m_Inputhandler.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    m_Inputhandler.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    m_Inputhandler.mouseMoved(x,y);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    m_Inputhandler.mouseDragged(x, y, button);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    m_Inputhandler.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    m_Inputhandler.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
    m_Inputhandler.mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
    m_Inputhandler.mouseExited(x, y);
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


