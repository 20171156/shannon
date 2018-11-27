#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = NULL;

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"));
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

MenuState::MenuState()
{

}

MenuState::~MenuState()
{

}