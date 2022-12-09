#pragma once
#include "Base.h"
#include "MenuCycle.h"
#include "Dictionary.h"
#include "Editor.h"
#include "WordGame.h"

class Homework : public Base
{
	//타자 게임 만들기
	// 메뉴 : 단어 등록, 게임
	// 
	//1. 단어 등록 도감 : 게임에 필요한 단어를 입력하면 파일에 저장
	//2. 파일에 저장된 단어 랜덤으로 불러와서 화면에 출력 -> 맞추면 포인트 획득
	//3. 시간이 지날 수록 단어가 여러개씩 늘어나며 난이도 올리기 
private:
	MenuCycle* curCycle = 0;

	Editor editor;
	WordGame game;

	enum class MenuState {
		INIT,
		MENU,
		CYCLE,
		EXIT,
	};
	MenuState menuState = MenuState::INIT;

	bool called_render = false;
	std::string renderTarget;
private:
	void Init();
	void PrintMenu();
	MenuState SelectMenu();

	void Update();
	void Render();
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

