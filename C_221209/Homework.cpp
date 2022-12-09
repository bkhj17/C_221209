#include "Homework.h"
#include <stdio.h>
#include <string.h>



void Homework::Init()
{
}

void Homework::PrintMenu()
{
	printf("1. 단어 등록\n");
	printf("2. 게임\n");
	printf("그 외. 종료\n");
	printf("-> ");
}

void Homework::Run()
{
	Init();
	while (menuState != MenuState::EXIT) {
		Update();
		Render();
	}

	printf("게임을 종료합니다.\n");
}

Homework::MenuState Homework::SelectMenu()
{
	int select;
	scanf_s("%d", &select);

	if (select == 1) {
		curCycle = &editor;
		return MenuState::CYCLE;
	}
	else if (select == 2) {
		curCycle = &game;
		return MenuState::CYCLE;
	}
	return MenuState::EXIT;
}

void Homework::Update()
{
	switch (menuState)
	{
	case Homework::MenuState::INIT:
		Init();
		called_render = true;
		menuState = MenuState::MENU;
		break;
	case Homework::MenuState::MENU:
		menuState = SelectMenu();
		break;
	case Homework::MenuState::CYCLE:
		curCycle->Update();
		if (curCycle->IsClose()) {
			curCycle = NULL;
			menuState = MenuState::MENU;
		}
		break;
	case Homework::MenuState::EXIT:
		break;
	default:
		break;
	}
}

void Homework::Render()
{
	if (curCycle) {
		renderTarget = "";
		if (curCycle->Render(renderTarget)) {
			system("cls");
			printf("%s", renderTarget.c_str());
		}
		return;
	}

	if(menuState != MenuState::EXIT && called_render) {
		system("cls");
		PrintMenu();
	}
}
