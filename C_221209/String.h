#pragma once
#include "Base.h"

//String 문자열
//char 배열
//상수는 ""로 표기
//문자열 마지막엔 null문자(\0)가 들어감(배열의 마지막이 아님!)

class String : public Base
{
	int GetStrLength(const char *);
	bool IsSameStr(char* str1, char* str2);
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

