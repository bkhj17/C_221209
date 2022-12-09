#include "WordGame.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Dictionary.h"
#include "UsefulFunc.h"

const int WordGame::LEVEL_WORD[WordGame::MAX_LEVEL] = {1, 2, 3, 4};
const int WordGame::LEVEL_TABLE[WordGame::MAX_LEVEL] = { 0, 3, 7, 12 };
std::string WordGame::buffer = "";

bool WordGame::IsClose()
{
    return gameState == GameState::CLOSE;
}

void WordGame::CheckTime()
{
    int now = clock();
    if (now - lastTime >= SEC) {
        lastTime = now;
        call_render = true;
        if ((lastTime - startTime)/SEC >= TIME_LIMIT)
            gameState = GameState::FAIL;
    }
}

int WordGame::GetLeftTime()
{
    return TIME_LIMIT+(startTime - lastTime)/SEC;
}

void WordGame::SetTargetWords()
{
    for (nowWord = 0; nowWord < LEVEL_WORD[level]; nowWord++) {
        int index = MakeRandByRange(0, Dictionary::GetInstance()->GetNumWords() - 1);
        targetWords[nowWord] = Dictionary::GetInstance()->GetWord(index);
    }
    call_render = true;
}

void WordGame::GetInput()
{
    if (_kbhit()) {
        char input = _getch();
        switch (input) {
        case 13: case ' ': //엔터, 스페이스
            CheckInputWord();
            break;
        case 8:             //백스페이스
            if (buffer.length() > 0) {
                buffer.pop_back();
            }
        break;
        default:
            if (input >= 65) {
                buffer += input;
            }
        }
        call_render = true;
    }

}

void WordGame::CheckInputWord()
{
    if (buffer == "")
        return;

    for (int i = 0; i < LEVEL_WORD[level]; i++) {
        if (buffer == targetWords[i]) {
            targetWords[i] = std::string(targetWords[i].length() , ' ');
            nowWord--;
            call_render = true;
            break;
        }
    }

    if (nowWord == 0) {
        PlusScore();
        SetTargetWords();
    }

    buffer = "";
}

void WordGame::PlusScore()
{
    score++;
    if (score >= LEVEL_TABLE[level]) {
        if (LevelUp())
            gameState = GameState::WIN;
    }
    lastTime = clock();
}

bool WordGame::LevelUp()
{
    level++;
    return ++level == MAX_LEVEL;
}

void WordGame::Ready()
{
    fflush(stdin);
	if (_kbhit()) {
		int input = _getch();
        if (input == 13) {
            gameState = GameState::PLAY;
            SetTargetWords();
            lastTime = startTime = clock();
            return;
        }
	}
    
}

void WordGame::WaitClose()
{
    if (_kbhit())
        gameState = GameState::CLOSE;
}

void WordGame::Init()
{
    level = 0;
    score = 0;

    buffer = "";
    nowWord = 0;

    call_render = true;
}

void WordGame::Update()
{

	switch (gameState)
	{
	case WordGame::GameState::INIT:
		Init();
		gameState = GameState::READY;
		break;
	case WordGame::GameState::READY:
		Ready();
		break;
	case WordGame::GameState::PLAY:
        CheckTime();
		GetInput();
		break;
    case WordGame::GameState::WIN:
	case WordGame::GameState::FAIL:
        WaitClose();
		break;
	case WordGame::GameState::CLOSE:
		break;
	default:
		break;
	}
}

bool WordGame::Render(std::string& renderTarget)
{
    if (!call_render)
        return false;

    renderTarget += "Score : ";
    renderTarget += std::to_string(score);
    renderTarget += "  Level : ";
    renderTarget += std::to_string(level + 1);

    renderTarget += "     Time : ";
    renderTarget += std::to_string(GetLeftTime());
    renderTarget += "\n=====================================\n\n";
    for (int i = 0; i < LEVEL_WORD[level]; i++) {
        renderTarget += targetWords[i];
        renderTarget += " ";
    }
    renderTarget += "\n\n=====================================\n";
    if(gameState == GameState::READY)
        renderTarget += "시작하려면 Enter";
    else if(gameState == GameState::WIN)
        renderTarget += "승리! 아무 키를 눌러 메뉴로";
    else if (gameState == GameState::FAIL)
        renderTarget += "패배... 아무 키를 눌러 메뉴로";
    else {
        renderTarget += "-> ";
        renderTarget += buffer;
    }

    call_render = false;
    return true;
}

void WordGame::BeforeClose()
{
}