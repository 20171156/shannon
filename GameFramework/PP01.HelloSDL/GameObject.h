#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
    //순수 가상 함수 선언
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};