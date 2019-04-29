#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Inputhandler.h"

class MainLevel
{
private:
    std::string m_SettingsFilename;
    ofxAssimpModelLoader m_ModelLobby;
    //ofCamera m_Cam;
    ofEasyCam m_Cam;

    ofLight mLight;

    const Inputhandler* m_Inputhandler;
public:
    MainLevel( const std::string& settingsFilename, const Inputhandler* inputhandler);
    ~MainLevel();

    void setup();
    void draw();

private:
    void setupCamera();
    void setupLight();
};

