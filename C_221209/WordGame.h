#pragma once
#include "MenuCycle.h"
class WordGame :
    public MenuCycle
{
    //나타나는 단어
    static const int MAX_WORD[4];
    int level = 0;
    int now_word = 0;
    


public:
    // MenuCycle을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual bool Render(std::string& renderTarget) override;
    virtual void BeforeClose() override;

    // MenuCycle을(를) 통해 상속됨
    virtual bool IsClose() override;
};

