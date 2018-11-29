#pragma once
#include "GameObject.h"
#include <iostream>
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:

    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
protected:
    //int m_x;
    //int m_y;   

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
	int m_numFrames;
    std::string m_textureID;
};