#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Board {
	int **table;
	int rows;
	int cols;
	int emptyTileRow;
	int emptyTileCol;
};


Board * createBoard(int rows, int cols)
{

	if (rows <= 0 || cols <= 0)
		return NULL;
	else
	{
		Board *newlyCreatedBoard = (Board *)malloc(sizeof(Board));
		int **arr = (int**)malloc(sizeof(int*)*rows);
		for (int iter = 0; iter <rows; iter++)
			arr[iter] = (int*)malloc(sizeof(int)*cols);

		newlyCreatedBoard->table = arr;
		newlyCreatedBoard->cols = cols;
		newlyCreatedBoard->rows = rows;
		newlyCreatedBoard->emptyTileCol = 0;
		newlyCreatedBoard->emptyTileRow = 0;
		return newlyCreatedBoard;
	}
}


void initializeBoard(Board * source, int *tobeCopiedArray, int rows, int cols)
{
	if (rows >= 0 && cols >= 0 && source != NULL && tobeCopiedArray != NULL)
	{
		source->rows = rows;
		source->cols = cols;
		int iter3 = 0;
		for (int iter1 = 0; iter1 < rows; iter1++)
			for (int iter2 = 0; iter2 < cols; iter2++)
			{
				if ((*(tobeCopiedArray + (iter3))) == 0)
				{
					source->emptyTileRow = iter1;
					source->emptyTileCol = iter2;
				}
				source->table[iter1][iter2] = (*(tobeCopiedArray + (iter3++)));
			}
	}
}

int checkBoard(Board * board)
{
	int temp = 1;
	for (int iter1 = 0; iter1 < board->rows; iter1++)
	{
		for (int iter2 = 0; iter2 <board->cols; iter2++)
		{
			if (iter1 != board->rows - 1 && iter2 != board->cols - 1 && board->table[iter1][iter2] != (temp + iter2))
				return 0;
		}
		temp = temp + board->cols;
	}
	if (board->table[board->rows - 1][board->cols - 1] != 0)
		return 0;
	if (board->emptyTileRow != board->rows - 1 || board->emptyTileCol != board->cols - 1)
		return 0;
	return 1;
}



void drawBoardOnScreen(Board *board){
	printf("\n\n\n\n\t\t\t\t****       C15Puzzle       ****\n\n");

	for (int iter1 = 0; iter1 < board->rows; iter1++)
	{
		printf("\t\t\t\t\t");
		for (int iter2 = 0; iter2 < board->cols; iter2++)
		{
			printf("%-3d", board->table[iter1][iter2]);
		}
		printf("\n\n");
	}
	printf("----------[W] UP -------- [S] Down ------- [A] LEFT ----------- [D] Right-----------");
}

void clearScreen()
{
	system("cls");
}

void clearAndRedrawScreen(Board * board)
{
	system("cls");
	drawBoardOnScreen(board);
}
