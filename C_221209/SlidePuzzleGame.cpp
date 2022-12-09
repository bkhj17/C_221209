#include "SlidePuzzleGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void SlidePuzzleGame::SetBoard()
{
	for (uint y = 0; y < BOARD_SIZE; y++) {
		for (uint x = 0; x < BOARD_SIZE; x++) {
			int index = y * BOARD_SIZE + x;
			puzzleBoard[y][x] = index;
		}
	}
}

void SlidePuzzleGame::ShuffleBoard()
{
	for (int i = 0; i < SHUFFLE_COUNT; i++) {
		int r = rand() % 4;
		switch (r) {
		case 0:
			MoveSpace(&space, Direction::UP);
			break;
		case 1:
			MoveSpace(&space, Direction::DOWN);
			break;
		case 2:
			MoveSpace(&space, Direction::LEFT);
			break;
		case 3:
			MoveSpace(&space, Direction::RIGHT);
			break;
		}
	}

}

SlidePuzzleGame::Direction SlidePuzzleGame::InputDirection()
{
	int input;
	while (1) {
		if (_kbhit()) {
			input = _getch();
			return Direction(input);
		}
	}
}

void SlidePuzzleGame::PrintBoard()
{
	system("cls");
	for (uint y = 0; y < BOARD_SIZE; y++) {
		for (uint x = 0; x < BOARD_SIZE; x++) {
			if(puzzleBoard[y][x])
				printf("%2d ", puzzleBoard[y][x]);
			else
				printf("¡Ý ");
		}
		printf("\n");
	}
}

SlidePuzzleGame::GameState SlidePuzzleGame::CheckBorad()
{
	for (uint y = 0; y < BOARD_SIZE; y++) {
		for (uint x = 0; x < BOARD_SIZE; x++) {
			if (puzzleBoard[y][x] != y * BOARD_SIZE + x)
				return GameState::INPUT_MOVE;
		}
	}

	return GameState::GAME_CLEAR;
}


void SlidePuzzleGame::Swap(uint& x, uint& y)
{
	uint tmp = x;
	x = y;
	y = tmp;
}

void SlidePuzzleGame::MoveSpace(Point* pos, Direction dir)
{
	Point next_pos;
	next_pos.x = pos->x;
	next_pos.y = pos->y;

	switch (dir)
	{
	case Direction::UP:
		next_pos.x += 0;
		next_pos.y += -1;
		break;
	case SlidePuzzleGame::Direction::DOWN:
		next_pos.x += 0;
		next_pos.y += 1;
		break;
	case SlidePuzzleGame::Direction::LEFT:
		next_pos.x += -1;
		next_pos.y += 0;
		break;
	case SlidePuzzleGame::Direction::RIGHT:
		next_pos.x += 1;
		next_pos.y += 0;
		break;
	default:
		break;
	}

	if (next_pos.x < 0 || next_pos.x >= BOARD_SIZE || next_pos.y < 0 || next_pos.y >= BOARD_SIZE)
		return;

	Swap(puzzleBoard[pos->y][pos->x], puzzleBoard[next_pos.y][next_pos.x]);
	pos->x = next_pos.x;
	pos->y = next_pos.y;
}

void SlidePuzzleGame::Run()
{
	while (true) {
		switch (gameState)
		{
		case SlidePuzzleGame::GameState::SET_BOARD:
			SetBoard();
			gameState = GameState::SHUFFLE;
			break;
		case SlidePuzzleGame::GameState::SHUFFLE:
			ShuffleBoard();
			gameState = GameState::PRINT_BOARD;
			break;
		case SlidePuzzleGame::GameState::PRINT_BOARD:
			PrintBoard();
			gameState = GameState::CHECK_BOARD;
			break;
		case SlidePuzzleGame::GameState::INPUT_MOVE:
		{
			Direction dir = InputDirection();
			MoveSpace(&space, dir);
			gameState = GameState::PRINT_BOARD;
		}
			break;
		case SlidePuzzleGame::GameState::CHECK_BOARD:
			gameState = CheckBorad();
			break;
		case SlidePuzzleGame::GameState::GAME_CLEAR:
			return;
			break;
		default:
			break;
		}
	}
}
