#include "task.h"
#include "agent.h"
#include "greedy.h"
#include "minmax.h"

int DEBUG=1;
int weights[GAMESIZE][GAMESIZE]={
	{99, -8, 8, 6, 6, 8, -8, 99},
	{-8, -24, -4, -3, -3, -4, -24, -8},
	{8, -4, 7, 4, 4, 7, -4, 8},
	{6, -3, 4, 0, 0, 4, -3, 6},
	{6, -3, 4, 0, 0, 4, -3, 6},
	{8, -4, 7, 4, 4, 7, -4, 8},
	{-8, -24, -4, -3, -3, -4, -24, -8},
	{99, -8, 8, 6, 6, 8, -8, 99}
};

coord move_dirc[8] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};


int main()
{
	Task task_info("input.txt");
	task_info.PrintTaskInfo();
	vector<board_info> new_board_vector;
	vector<board_info>::iterator it;
	if (task_info.task_no == 1){
		Greedy greedy;
		greedy.init(task_info);
		new_board_vector = greedy.get_new_boards_vector(greedy.root_board, task_info.your_player);
		sort(new_board_vector.begin(), new_board_vector.end(), compare_max_min);
		cout<<greedy.print_only_board(new_board_vector[0].board);
		free_boards(new_board_vector);
	}else if(task_info.task_no==2){
		Minmax minmax;
		minmax.init(task_info);
	    minmax.run_min_max(minmax.root_board, minmax.depth, task_info.your_player);
	}
	//while(1);
	return (0); 
}


int compare_max_min(board_info &board1, board_info &board2)
{
	if(board1.weight > board2.weight)
		return 1;
	else if(board1.weight == board2.weight)
		return compare_order(board1, board2);
	else
		return 0;
}

int compare_min_max(board_info &board1, board_info &board2)
{
	if(board1.weight < board2.weight)
		return 1;
	else if(board1.weight == board2.weight)
		return compare_order(board1, board2);
	else
		return 0;
}

int compare_order(board_info &board1, board_info &board2)
{
	if(board1.x<board2.x)
		return 1;
	else if(board1.x==board2.x){
		if(board1.y<board2.y)
			return 1;
		else
			return 0;	
	}else
		return 0;
}

void free_board_mem(char **board)
{
	for (int j = 0; j < 8 ; j++)
		delete[] board[j];
	delete[] board;
}

void free_boards(vector<board_info> &new_board_vector)
{
	int count = 0;
	for(vector<board_info>::iterator it=new_board_vector.begin(); it!=new_board_vector.end(); ++it){
		free_board_mem(it->board);
		count++;
	}
	cout << count << "boards are freed"<<endl;
}
