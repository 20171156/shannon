#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"

//class GameObject;
//class Player;

class Game
{
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos,
        int width, int height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }



private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    //int m_currentFrame;
    GameObject m_go;//GameObject.h狼 按眉积己
    Player m_player;//Player.h狼 按眉积己
};