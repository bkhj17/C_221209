#pragma once
#include "Base.h"
//파일입출력

class FileIo :
    public Base
{
    static const char filename[];
    static const int STR_LENGTH = 128;
    struct Weapon {
        char name[STR_LENGTH];
        int price;
    };

    void Save();
    void Load();
public:
    // Base을(를) 통해 상속됨
    virtual void Run() override;
};

