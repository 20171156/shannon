#include "SDL.h"


class InputHandler
{
public:
    ~InputHandler() {}
    static InputHandler* Instance()
    {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean();  // 디바이스 관련 초기화된 부분을 clear 



private:
    InputHandler();
    const Uint8* m_keyStates;
    static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
