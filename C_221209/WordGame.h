#pragma once
#include "MenuCycle.h"
#include <string>

class WordGame :
    public MenuCycle
{
    static const int MAX_LEVEL = 4;
    static const int MAX_WORD = 4;
    static const int SEC = 1000;
    static const int TIME_LIMIT = 60;
    static const int LEVEL_TABLE[MAX_LEVEL];
    static const int LEVEL_WORD[MAX_LEVEL];

    //��Ÿ���� �ܾ�

    int level = 0;
    int score = 0;

    int nowWord = 0;
    static std::string buffer;
    std::string targetWords[MAX_WORD];
    //
    

    enum class GameState {
        INIT,
        READY,
        PLAY,
        WIN,
        FAIL, 
        CLOSE
    };
    GameState gameState = GameState::INIT;
    //�ܾ ��Ÿ����. 
    //���� �ð� �ȿ� �� ġ�� ���� ����
    //���� Ƚ�� ����� ������ ������ ���� �� ����
    
    time_t startTime = 0, lastTime = 0;
    void CheckTime();
    int GetLeftTime();

    void SetTargetWords();


    void GetInput();
    void CheckInputWord();

    void PlusScore();
    bool LevelUp();

    void Ready();

    void WaitClose();

    bool call_render;
public:
    // MenuCycle��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual bool Render(std::string& renderTarget) override;
    virtual void BeforeClose() override;

    // MenuCycle��(��) ���� ��ӵ�
    virtual bool IsClose() override;
};

