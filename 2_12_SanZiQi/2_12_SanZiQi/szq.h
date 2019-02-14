#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<assert.h>

#define ROW 5
#define COL  5
#define LONG_ture   5
#define ROWS ROW+2
#define COLS  COL+2

#define LONG  LONG_ture-1

void InitBoard(char arr[ROWS][COLS], int rows, int cols);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void PlayerMov(char arr[ROWS][COLS], int row, int col);
void ComputerMov(char arr[ROWS][COLS], int row, int col);
char JudgeWin(char arr[ROWS][COLS], int row, int col);

