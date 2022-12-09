#include "WordGame.h"

const int MAX_WORD[4] = {1, 2, 4, 8};

bool WordGame::IsClose()
{
    return false;
}

void WordGame::Init()
{
    level = 0;
    now_word = 0;


}

void WordGame::Update()
{
}

bool WordGame::Render(std::string& renderTarget)
{
    return true;
}

void WordGame::BeforeClose()
{
}