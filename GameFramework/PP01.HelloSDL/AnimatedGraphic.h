#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
private:
    int m_animSpeed;

public:

	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	virtual void update();
    virtual void draw();
    virtual void clean();

};