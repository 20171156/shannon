#pragma once
#include "SDLGameObject.h"

class Ball : public SDLGameObject
{
private:
	void handleInput();
public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};