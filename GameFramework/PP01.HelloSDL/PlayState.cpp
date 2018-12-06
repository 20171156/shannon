#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "SDLGameObject.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = NULL;

void PlayState::update()
{
	//여러군데에서 동시에 나타나는 코드들. 어떻게 최적화를 할 것인가?

    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

    if (checkCollision(
        dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
        dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
    }
}

void PlayState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/animate.png",
        "animate", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TextureManager::Instance()->load("assets/wall.png",
        "wall", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ball.png",
		"ball", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(new LoaderParams(20, 20, 128, 82, "animate"));
	GameObject* enemy = new Enemy(new LoaderParams(450, 100, 128, 55, "wall"));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
    for (int i = 0 ; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TextureManager::Instance()->clearFromTextureMap("helicopter");
    std::cout << "exiting PlayState\n";
    return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

PlayState::PlayState()
{

}

PlayState::~PlayState()
{

}