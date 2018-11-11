#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
    //순수 가상 함수
    //추상 클래스가 됨
    //객체 생성이 불가능
    //연결고리 역할만 할 수 있게끔 역할 고정을 함
    //상속받아서 만든 객체에만 의미가 있다는 것을 바로 알려줌
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};