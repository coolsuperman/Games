#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<assert.h>

#define ROW   9
#define COL   9
#define ROWS  ROW+2
#define COLS    COL+2

#define BOM   10


void InitBoard(char arr[ROWS][COLS], int rows, int cols, char want);
void PrintBoard(char arr[ROWS][COLS], int row, int col);
void SetBom(char ture[ROWS][COLS], int row, int col);
void PyrMov(char ture[ROWS][COLS], char show[ROWS][COLS], int row, int col);