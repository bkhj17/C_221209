#pragma once
#include "Base.h"
#include <string>

class Test : public Base
{
	static const int LIMIT = 1000000000;
	static const int NUM_OF_NUMBER = 10;

	string s;
	int n;
	int cntNum[NUM_OF_NUMBER] = {};

	void GetCount(std::string s);
public:


	// Base을(를) 통해 상속됨
	virtual void Run() override;

};

