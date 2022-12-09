#include "BingoGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void BingoGame::SetBoard(uint (*board)[BOARD_SIZE])
{
	/*
	for (uint i = 0; i < BOARD_SIZE; i++) {
		for (uint j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = GetBoardNum(i * BOARD_SIZE + j, board);
		}
	}
	*/
	uint count = 0;
	for (uint* temp = (uint*)board; count < BOARD_SIZE * BOARD_SIZE; count++, temp++)
		*temp = GetBoardNum(count, board);
}

int BingoGame::GetRandomInRange(const int& minRange, const int& maxRange)
{
	return rand() % (maxRange - minRange + 1) + minRange;
}

uint BingoGame::GetBoardNum(const uint& count, uint(*board)[BOARD_SIZE])
{
	uint randomNum = 0;
	while (1) {
		randomNum = GetRandomInRange(MIN_NUMBER, MAX_NUMBER);
		bool check = false;

		for (int i = 0; i < count; i++) {
			//배열은 열 우선 배치!
			//2차원 배열 arr[R][C]에서 i번째 변수 => arr[i/C][i%C];
			if (randomNum == board[i / BOARD_SIZE][i % BOARD_SIZE]) {
				check = true;
				break;
			}
		}

		if (!check)
			break;
	}
	return randomNum;
}

void BingoGame::PrintBoard(uint(*board)[BOARD_SIZE])
{
	for (uint i = 0; i < BOARD_SIZE; i++) {
		for (uint j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == 0)
				printf("◎ ");
			else
				printf("%2d ", board[i][j]);
		}
		printf("\n");
	}

	printf("=====================\n");
}

uint BingoGame::InputNumberInRange(uint(*board)[BOARD_SIZE], const int& minRange, const int& maxRange)
{
	uint inputNumber = 0;

	while (true) {
		printf("%d부터 %d사이의 숫자를 입력하시오\n", minRange, maxRange);
		scanf_s("%d", &inputNumber);

		if (inputNumber < minRange || inputNumber > maxRange)
		{
			printf("범위 오류\n");
			continue;
		}

		bool check = false;
		for (uint i = 0; i < BOARD_SIZE; i++) {
			for (uint j = 0; j < BOARD_SIZE; j++) {
				if (board[i][j] == inputNumber) {
					check = true;
					break;
				}
			}

			if (check)
				break;
		}
		if (check) {
			printf("중복 숫자\n");
			continue;
		}

		break;

	}

	return inputNumber;
}

void BingoGame::CheckInputNumber(uint(*answerBoard)[BOARD_SIZE], uint(*inputBoard)[BOARD_SIZE], const uint& inputNumber)
{
	for (uint i = 0; i < BOARD_SIZE; i++) {
		for (uint j = 0; j < BOARD_SIZE; j++) {
			if (answerBoard[i][j] == inputNumber)
				inputBoard[i][j] = inputNumber;
		}
	}
}

BingoGame::GameState BingoGame::CheckBingo(uint(*board)[BOARD_SIZE], uint& attemptCount)
{
	int rowCount[BOARD_SIZE] = {};
	int colCount[BOARD_SIZE] = {};
	int diagonalCount[2] = {};
	uint bingoCount = 0;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] != 0) {
				rowCount[i]++;
				colCount[j]++;

				if (i == j)
					diagonalCount[0]++;
				if (i + j == BOARD_SIZE - 1)
					diagonalCount[1]++;
			}
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++) {
		if (rowCount[i] == BOARD_SIZE)
			bingoCount++;
		if (colCount[i] == BOARD_SIZE)
			bingoCount++;
	}

	for (int i = 0; i < 2; i++)
		if (diagonalCount[i] == BOARD_SIZE)
			bingoCount++;

	printf("%d번 시도하여 %d번 남았습니다.", 
		++attemptCount, 
		MAX_ATTEMPT_NUMBER - attemptCount);
	Sleep(1000);
	if (bingoCount >= CLEAR_BINGO_NUMBER)
		return GameState::GAME_CLEAR;
	else if(attemptCount == MAX_ATTEMPT_NUMBER)
		return GameState::GAME_OVER;
	return GameState::PRINT_BOARD;
}

void BingoGame::Run()
{
	while (true)
	{
		switch (gameState)
		{
		case GameState::SET_BOARD:
			SetBoard(answerBoard);
			gameState = GameState::PRINT_BOARD;
			break;
		case GameState::PRINT_BOARD:
			system("cls");
			printf("======BingoGame======\n");
			PrintBoard(answerBoard);
			PrintBoard(inputBoard);
			gameState = GameState::INPUT_NUMBER;
			break;
		case GameState::INPUT_NUMBER:
		{
			uint inputNum = InputNumberInRange(inputBoard, MIN_NUMBER, MAX_NUMBER);
			CheckInputNumber(answerBoard, inputBoard, inputNum);
			gameState = GameState::CHECK_BINGO;
		}
			break;
		case GameState::CHECK_BINGO:
		{
			CheckBingo(inputBoard, attemptCount);
			gameState = GameState::PRINT_BOARD;
		}
			break;
		case GameState::GAME_CLEAR:
			break;
		case GameState::GAME_OVER:
			break;
		default:
			break;
		}
	}
}
