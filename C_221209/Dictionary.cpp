#include "Dictionary.h"
#include <stdio.h>
#include <string.h>

Dictionary* Dictionary::instance = NULL;
const char* Dictionary::FILE_NAME = "Words.txt";

void Dictionary::Save()
{
	FILE* file = NULL;
	fopen_s(&file, FILE_NAME, "w");
	if (!file) {
		printf("파일 불러오기 실패\n");
		return;
	}

	fprintf_s(file, "%d\n", numWords);
	for (int i = 0; i < numWords; i++)
		fprintf_s(file, "%s ", words[i]);

	fclose(file);
}

void Dictionary::AddWord(const char* str)
{
	if (numWords == MAX_WORD_NUM) {
		printf("단어장 꽉 참\n");
		return;
	}

	sprintf_s(words[numWords++], "%s", str);
}
void Dictionary::Load()
{
	FILE* file = NULL;
	fopen_s(&file, FILE_NAME, "r");
	if (!file) {
		printf("파일 불러오기 실패\n");
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
	renderTarget += "[단어 목록 : "; 
	renderTarget += std::to_string(numWords);
	renderTarget += +"]\n";

	for (int i = 0; i < numWords; i++) {
		renderTarget += words[i];
		renderTarget += "\n";
	}
}

const char* Dictionary::GetWord(const int& index)
{
	if(index >= numWords)
		return nullptr;

	return words[index];
}

Dictionary* Dictionary::GetInstance()
{
	if (!instance)
		instance = new Dictionary();

	return instance;
}

Dictionary::Dictionary()
{
	Load();
}