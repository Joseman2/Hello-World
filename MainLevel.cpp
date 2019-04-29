#include "MainLevel.h"
#include "ofxXmlSettings.h"



MainLevel::MainLevel(const std::string& settingsFilename, const Inputhandler* inputhandler)
    :m_SettingsFilename(settingsFilename), m_Inputhandler(inputhandler)
{
}

MainLevel::~MainLevel()
{
}

void MainLevel::setup()
{
    // Graphic settings
    ofSetVerticalSync(true);
    ofBackground(20);
    ofSetSphereResolution(24);
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();
    //ofSetColor(255);
    ofEnableDepthTest();
    //ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    //ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSmoothLighting(true);
    //*****

    ofxXmlSettings settings;
    settings.loadFile(m_SettingsFilename);
    std::string levelModel = settings.getValue("MainLevel:Model","",0);

    // load Main Level Model
    if (!m_ModelLobby.loadModel(levelModel))
        throw std::exception("Could not load main level!");

    for (int meshNr(0); meshNr < m_ModelLobby.getMeshCount(); ++meshNr)
    {
        auto& meshHelper = m_ModelLobby.getMeshHelper(meshNr);
        if (meshHelper.assimpTexture.hasTexture())
        {
            auto path = meshHelper.assimpTexture.getTexturePath();
            int test(0);
        }


        std::string fileName(std::to_string(meshNr) + ".ply");
        m_ModelLobby.getMesh(meshNr).save(fileName, false);
        //m_ModelLobby.getMesh(meshNr).
    }

    setupCamera();

    setupLight();
}

void MainLevel::setupCamera()
{
    ofVec3f pos(0, 5, 0);
    ofVec3f lookAt(ofVec3f(0, 0, 0) + ofVec3f(0, 0, 1));
    m_Cam.setPosition(pos);
    m_Cam.lookAt(lookAt);
    m_Cam.setScale(1.0, -1.0, 1.0);
    m_Cam.setFarClip(15000);
}

void MainLevel::setupLight()
{
    mLight.setup();
    mLight.setPosition(0, 0, 0);
    mLight.setDiffuseColor(ofFloatColor(0.5, 0.5, 0.5));
    mLight.setAmbientColor(ofFloatColor(0.0, 0.0, 0.1));
}

void MainLevel::draw()
{
    m_Cam.begin();
    mLight.enable();
    m_ModelLobby.draw(ofPolyRenderMode::OF_MESH_FILL);
    mLight.disable();
    m_Cam.end();
}



