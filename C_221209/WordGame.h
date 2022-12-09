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

    //나타나는 단어

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
    //단어가 나타난다. 
    //제한 시간 안에 못 치면 게임 오버
    //일정 횟수 통과할 때마다 나오는 글자 수 증가
    
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
    // MenuCycle을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual bool Render(std::string& renderTarget) override;
    virtual void BeforeClose() override;

    // MenuCycle을(를) 통해 상속됨
    virtual bool IsClose() override;
};

