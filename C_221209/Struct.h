#pragma once
#include "Base.h"

class Struct : public Base
{
	//구조체(struct)
	//하나 이상의 변수를 그룹지어서 새로운 자료형으로 정의한 것
	//C방식
	//각 멤버에 접근할 때는 .찍어서 접근(구조체 포인터에서 참조할 경우 -> 사용)
	//구조체 패딩 : 선언된 멤버들을 4바이트 단위로 묶고 딱 맞지 않으면 빈 공간(패딩)을 둔다
	//클래스도 마찬가지이며 되도록 4byte 맞게끔 배치하자
	typedef struct {
		int attack;
		float criticalRate;
		char name[255];
	} Monster;

	void ShowMonsterInfo(Monster monster);	//값
	void ShowMonsterInfo(Monster* monster);	//주소참조
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

