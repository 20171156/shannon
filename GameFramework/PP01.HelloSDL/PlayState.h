#pragma once
#include "GameState.h"

class PlayState : public GameState
{
public:
	~PlayState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	PlayState();
	static const std::string s_playID;
	static PlayState* s_pInstance;
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
    //std::vector<GameObject*> m_gameObjects;
};
