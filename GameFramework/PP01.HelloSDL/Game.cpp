#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;


Game* Game::s_pInstance = NULL;

bool Game::init(const char* title, int xpos, int ypos,
    int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        }

        m_bRunning = true;

        //load 부분 대치
        if (!TextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
        {
            return false;
        }

        m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
        m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    }
    else
    {
        return false; // sdl could not initialize
    }
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear to the draw colour
    for (vector<GameObject*>::size_type i = 0;
        i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
    cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    for (vector<GameObject*>::size_type i = 0;
        i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

Game::Game()
{

}

Game::~Game()
{

}