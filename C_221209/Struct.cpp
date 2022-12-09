#include "Struct.h"
#include <string.h>
#include <stdio.h>

void Struct::ShowMonsterInfo(Monster monster)
{
	printf("Name : %s\n", monster.name);
	printf("ATK : %d\n", monster.attack);
	printf("CRT : %.1f\n", monster.criticalRate);
}
void Struct::ShowMonsterInfo(Monster* monster)
{
	printf("Name : %s\n", monster->name);
	printf("ATK : %d\n", monster->attack);
	printf("CRT : %.1f\n", monster->criticalRate);
}

void Struct::Run()
{
	Monster monster;
	strcpy_s(monster.name, "∏ÛΩ∫≈Õ");
	monster.attack = 10;
	monster.criticalRate = 0.5f;
	ShowMonsterInfo(monster);

	printf("%d\n", &(monster.attack));
	printf("%d\n", &(monster.criticalRate));
	printf("%d\n", &(monster.name));
}
