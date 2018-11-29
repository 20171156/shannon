#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : SDLGameObject
{
private:
	int m_animSpeed;

public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	virtual void update();
};