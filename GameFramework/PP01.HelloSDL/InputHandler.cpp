#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = NULL;

InputHandler::InputHandler()
{
    // 생성자 
}

void InputHandler::clean()
{
    // 향후 추가 
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keyStates != 0) {
        if (m_keyStates[key] == 1)
        {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYUP)
        {
            m_keyStates = SDL_GetKeyboardState(0);
        }
        if (event.type == SDL_KEYDOWN)
        {
            m_keyStates = SDL_GetKeyboardState(0);
        }
        if (event.type == SDL_QUIT)
        {
            TheGame::Instance()->quit();
        }
    }
}