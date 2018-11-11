#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>

class InputHandler
{
public:
    ~InputHandler() {}

    enum mouse_buttons
    {
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2
    };

    static InputHandler* Instance()
    {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    Vector2D* getMousePosition();

    bool isKeyDown(SDL_Scancode key);
    bool getMouseButtonState(int buttonNumber);

    void update();
    void clean();  // 디바이스 관련 초기화된 부분을 clear 


    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);
    void onKeyDown();
    void onKeyUp();

private:
    InputHandler();

    SDL_Event event;

    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    const Uint8* m_keyStates;
    static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
