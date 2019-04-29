#include "Inputhandler.h"

Inputhandler::Inputhandler()
{
}

Inputhandler::~Inputhandler()
{
}

void Inputhandler::keyPressed(int key) 
{
    if(m_PressedKeys.find(key) == m_PressedKeys.end())
        m_PressedKeys[key] = std::chrono::high_resolution_clock::now();

}

void Inputhandler::keyReleased(int key) 
{
    m_PressedKeys.erase(key); 
}

void Inputhandler::mouseMoved(int x, int y) 
{

}

void Inputhandler::mouseDragged(int x, int y, int button) 
{

}

void Inputhandler::mousePressed(int x, int y, int button) 
{

}

void Inputhandler::mouseReleased(int x, int y, int button) 
{

}

void Inputhandler::mouseEntered(int x, int y) 
{

}

void Inputhandler::mouseExited(int x, int y) 
{

}
