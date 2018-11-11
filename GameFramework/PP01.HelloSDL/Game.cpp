#include "Game.h"
#include "GameObject.h"
#include "Player.h"
using namespace std;

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
        m_go.load(100, 100, 128, 82, "animate");//게임오브젝트
        m_player.load(300, 300, 128, 82, "animate");//플레이어
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
    SDL_RenderClear(m_pRenderer);
    //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    //TextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
    //TextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
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
    //m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    m_go.update();
    m_player.update();
}

Game::Game()
{

}

Game::~Game()
{

}