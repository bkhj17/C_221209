#pragma once
#include "Base.h"

//String ���ڿ�
//char �迭
//����� ""�� ǥ��
//���ڿ� �������� null����(\0)�� ��(�迭�� �������� �ƴ�!)

class String : public Base
{
	int GetStrLength(const char *);
	bool IsSameStr(char* str1, char* str2);
public:
	// Base��(��) ���� ��ӵ�
	virtual void Run() override;
};

