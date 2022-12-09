#pragma once
#include "Base.h"
#include "MenuCycle.h"
#include "Dictionary.h"
#include "Editor.h"
#include "WordGame.h"

class Homework : public Base
{
	//Ÿ�� ���� �����
	// �޴� : �ܾ� ���, ����
	// 
	//1. �ܾ� ��� ���� : ���ӿ� �ʿ��� �ܾ �Է��ϸ� ���Ͽ� ����
	//2. ���Ͽ� ����� �ܾ� �������� �ҷ��ͼ� ȭ�鿡 ��� -> ���߸� ����Ʈ ȹ��
	//3. �ð��� ���� ���� �ܾ �������� �þ�� ���̵� �ø��� 
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
	// Base��(��) ���� ��ӵ�
	virtual void Run() override;
};

