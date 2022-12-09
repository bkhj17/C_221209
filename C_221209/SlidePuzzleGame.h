#pragma once
#include "Base.h"
#include "UsefulType.h"

class SlidePuzzleGame : public Base
{
	static const int BOARD_SIZE = 4;
	static const int SHUFFLE_COUNT = 1000;
	
	enum class GameState {
		SET_BOARD,
		SHUFFLE,
		PRINT_BOARD,
		INPUT_MOVE,
		CHECK_BOARD,
		GAME_CLEAR,
	};


	struct Point {	//∆€¡Ò ¡¬«•
		uint x = 0, y = 0;
	};
	Point space;

	enum class Direction {
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};

	uint puzzleBoard[BOARD_SIZE][BOARD_SIZE] = {};
	GameState gameState = GameState::SET_BOARD;

	void SetBoard();
	void ShuffleBoard();

	Direction InputDirection();
	void PrintBoard();
	GameState CheckBorad();

	void Swap(uint& x, uint& y);

	void MoveSpace(Point* pos, Direction dir);
public:
	// Base¿ª(∏¶) ≈Î«ÿ ªÛº”µ 
	virtual void Run() override;
};

