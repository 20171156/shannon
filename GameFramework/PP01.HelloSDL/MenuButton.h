#pragma once
#include "SDLGameObject.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:
    void(*m_callback)();
    MenuButton(const LoaderParams* pParams, void(*callback)());
	//MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
    bool m_bReleased;
};