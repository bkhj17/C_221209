#pragma once
#include "Base.h"

class Struct : public Base
{
	//����ü(struct)
	//�ϳ� �̻��� ������ �׷���� ���ο� �ڷ������� ������ ��
	//C���
	//�� ����� ������ ���� .�� ����(����ü �����Ϳ��� ������ ��� -> ���)
	//����ü �е� : ����� ������� 4����Ʈ ������ ���� �� ���� ������ �� ����(�е�)�� �д�
	//Ŭ������ ���������̸� �ǵ��� 4byte �°Բ� ��ġ����
	typedef struct {
		int attack;
		float criticalRate;
		char name[255];
	} Monster;

	void ShowMonsterInfo(Monster monster);	//��
	void ShowMonsterInfo(Monster* monster);	//�ּ�����
public:
	// Base��(��) ���� ��ӵ�
	virtual void Run() override;
};

