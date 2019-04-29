#pragma once
#include <map>
#include "ofMain.h"
class Inputhandler
{
private:
    std::map<int, std::chrono::high_resolution_clock::time_point> m_PressedKeys;
    ofVec2f m_MousePoint;

public:
    Inputhandler();
    ~Inputhandler();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
};

