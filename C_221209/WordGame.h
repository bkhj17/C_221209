#pragma once
#include "MenuCycle.h"
class WordGame :
    public MenuCycle
{
    //��Ÿ���� �ܾ�
    static const int MAX_WORD[4];
    int level = 0;
    int now_word = 0;
    


public:
    // MenuCycle��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual bool Render(std::string& renderTarget) override;
    virtual void BeforeClose() override;

    // MenuCycle��(��) ���� ��ӵ�
    virtual bool IsClose() override;
};

