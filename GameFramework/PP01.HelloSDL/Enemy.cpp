#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.001);
    m_numFrames = 5;
}

void Enemy::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-10);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(10);
    }
}

void Enemy::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100)  % m_numFrames));
	if (m_position.getY() < 0) {
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-2);
	}
	SDLGameObject::update();

    //m_velocity.setX(0);
    //m_velocity.setY(0);
    //handleInput();
    //m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
    ////m_acceleration.setX(1);
    //SDLGameObject::update();
}

void Enemy::clean()
{
}