#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#define GAMESIZE 8
using namespace std;

typedef struct coord_t{
	int x;
	int y;
}coord;

typedef struct board_info_t{
	int x;
	int y;
	char tile;
	char **board;
	int weight;
}board_info;
extern int DEBUG;
extern int weights[GAMESIZE][GAMESIZE];
extern int compare_min_max(board_info &board1, board_info &board2);
extern int compare_max_min(board_info &board1, board_info &board2);
extern void free_board_mem(char **board);
extern void free_boards(vector<board_info> &new_board_vector);
#endif
