#include "Dictionary.h"
#include <stdio.h>
#include <string.h>

const char* Dictionary::FILE_NAME = "Words.txt";

void Dictionary::Save()
{
	FILE* file = NULL;
	fopen_s(&file, FILE_NAME, "w");
	if (!file) {
		printf("���� �ҷ����� ����\n");
		return;
	}


	fprintf_s(file, "%d\n", numWords);
	for (int i = 0; i < numWords; i++)
		fprintf_s(file, "%s ", words[i]);
}

void Dictionary::AddWord(const char* str)
{
	if (numWords == MAX_WORD_NUM) {
		printf("�ܾ��� �� ��\n");
		return;
	}

	sprintf_s(words[numWords++], "%s", str);
}
void Dictionary::Load()
{
	FILE* file = NULL;
	fopen_s(&file, FILE_NAME, "r");
	if (!file) {
		printf("���� �ҷ����� ����\n");
		return;
	}

	fscanf_s(file, "%d", &numWords);
	for (int i = 0; i < numWords; i++) {
		fscanf_s(file, "%s", words[i], MAX_LENGTH);
	}

	fclose(file);
}

void Dictionary::PrintWords(std::string& renderTarget)
{
	renderTarget += "[�ܾ� ��� : "; 
	renderTarget += std::to_string(numWords);
	renderTarget += +"]\n";

	for (int i = 0; i < numWords; i++) {
		renderTarget += words[i];
		renderTarget += "\n";
	}
}

Dictionary::Dictionary()
{
	Load();
}