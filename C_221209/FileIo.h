#pragma once
#include "Base.h"
//���������

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
    // Base��(��) ���� ��ӵ�
    virtual void Run() override;
};

