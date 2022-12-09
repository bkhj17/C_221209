#pragma once
#include <string>

class Dictionary
{
private:
	static const char* FILE_NAME;
	static const int MAX_WORD_NUM = 64;
public:
	static const int MAX_LENGTH = 128;
private:
	int numWords = 0;
	char words[MAX_WORD_NUM][MAX_LENGTH] = {};
private:
	Dictionary();
	~Dictionary() {}
	static Dictionary* instance;


public:
	enum class InputResult {
		FULL,
		ALREADY,
		SUCCEED
	};
	InputResult AddWord(const char* str);
	void Save();
	void Load();

	void PrintWords(std::string& renderTarget);
	const char* GetWord(const int& index);
	int GetNumWords() const { return numWords; }

	bool IsFull();
	bool IsInDictionary(const char* str);
public:
	static Dictionary* GetInstance();
	static void Delete() { if (instance) delete(instance); }
};

