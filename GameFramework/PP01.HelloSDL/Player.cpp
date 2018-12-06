#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include "Ball.h"
#include "TextureManager.h"
#include "SDLGameObject.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(10);
}

void Player::handleInput()
{
    /*Vector2D* target = TheInputHandler::Instance()->getMousePosition();
    m_velocity = *target - m_position;
    m_velocity /= 50;*/

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
	/*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		GameObject* ball = new Ball(new LoaderParams(20, 20, 128, 82, "ball"));
		m_gameObjects.push_back(new Ball(new LoaderParams(m_position.getX() + 100, m_position.getY() + 20, 40, 40, "ball")));

	}*/

}

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
    //m_acceleration.setX(1);
    SDLGameObject::update();
}

void Player::clean()
{
}