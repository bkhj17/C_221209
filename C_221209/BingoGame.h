#pragma once
#include "Base.h"
#include "UsefulType.h"

class BingoGame : public Base
{
	static const int BOARD_SIZE = 5;
	static const int MIN_NUMBER = 1;
	static const int MAX_NUMBER = 99;
	static const int CLEAR_BINGO_NUMBER = 5;
	static const int MAX_ATTEMPT_NUMBER = 30;

	enum class GameState {
		SET_BOARD,
		PRINT_BOARD,
		INPUT_NUMBER,
		CHECK_BINGO,
		GAME_CLEAR,
		GAME_OVER,
	};
	

	uint answerBoard[BOARD_SIZE][BOARD_SIZE] = {};
	uint inputBoard[BOARD_SIZE][BOARD_SIZE] = {};

	GameState gameState = GameState::SET_BOARD;

	uint attemptCount = 0;

private:
	void SetBoard(uint (*board)[BOARD_SIZE]);	//board[][BOARD_SIZE]여도 상관없음
	int GetRandomInRange(const int& minRange, const int& maxRange);
	uint GetBoardNum(const uint& count, uint (*board)[BOARD_SIZE]);
	void PrintBoard(uint(*board)[BOARD_SIZE]);
	uint InputNumberInRange(uint (*board)[BOARD_SIZE], const int& minRange, const int& maxRange);
	void CheckInputNumber(uint(*answerBoard)[BOARD_SIZE], uint(*inputBoard)[BOARD_SIZE], const uint& inputNumber);
	GameState CheckBingo(uint(*board)[BOARD_SIZE], uint& inputCount);
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

