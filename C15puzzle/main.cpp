#define _CRT_SECURE_NO_WARNINGS
#include "C15BoardUtils.h"
#include "C15UserUtils.h"
#include "C15MovesUtils.h"



int main()
{
	char *player = (char*)malloc(sizeof(char) * 50);
	printf("Enter User name:\n");
	scanf("%[^\n]", player);
	User *user = createUser(player);
	printf("Enter rows and columns:\n");
	Board *board = createBoard(4, 4);
	int table[4][4] = { 1,2,3,4,0,5,7,8,10, 6, 11, 12,9, 13, 14, 15 };

	initializeBoard(board, (int *)table, 4, 4);
	clearAndRedrawScreen(board);
	printUser(user);
	while (!checkBoard(board))
	{
		char c = takeInput();
		playMove(board, user, c);
		clearAndRedrawScreen(board);
	}
	clearAndRedrawScreen(board);
	printf("\n\n\n------------------------------Game Completed-----------------------\n\n\n");
	printUser(user);
	system("pause");
	return 0;
}




