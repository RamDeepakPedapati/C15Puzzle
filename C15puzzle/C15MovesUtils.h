int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);


char takeInput()
{
	char c = ' ';
	while (!isValidInput(c))
	{
		fflush(stdin);
		scanf("%c", &c);
		fflush(stdin);
	}

	return c;
}

int isValidInput(char letter)
{
	if (letter == 97 || letter == 100 || letter == 115 || letter == 119 || letter == 65 || letter == 68 || letter == 83 || letter == 87)
		return 1;
	else
		return 0;
}

int processInput(Board *board, char inputChar)
{
	if (isValidInput(inputChar))
	{
		if (inputChar == 'a' || inputChar == 'A')
		{
			if (board->emptyTileCol + 1 <= board->cols - 1)
			{
				goRight(board);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (inputChar == 'd' || inputChar == 'D')
		{
			if (board->emptyTileCol - 1 >= 0)
			{
				goLeft(board);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (inputChar == 'w' || inputChar == 'W')
		{
			if (board->emptyTileRow + 1 <= board->rows - 1)
			{
				goDown(board);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (inputChar == 's' || inputChar == 'S')
		{
			if (board->emptyTileRow - 1 >= 0)
			{
				goUp(board);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 1;
	}
	return 1;
}

void playMove(Board *board, User *user, char choice)
{
	modifyMoveCountBasedOnProccessInput(user, processInput(board, choice));
	clearAndRedrawScreen(board);
	printUser(user);
}


int goLeft(Board *board)
{
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow, board->emptyTileCol - 1);
	board->emptyTileCol = board->emptyTileCol - 1;
	return 0;
}

int goRight(Board *board)
{
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow, board->emptyTileCol + 1);
	board->emptyTileCol = board->emptyTileCol + 1;
	return 0;
}


int goUp(Board *board)
{
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow - 1, board->emptyTileCol);
	board->emptyTileRow = board->emptyTileRow - 1;
	return 0;
}


int goDown(Board *board)
{
	swap(board, board->emptyTileRow, board->emptyTileCol, board->emptyTileRow + 1, board->emptyTileCol);
	board->emptyTileRow = board->emptyTileRow + 1;
	return 0;
}

void swap(Board *board, int x1, int y1, int x2, int y2)
{
	int temp;
	temp = board->table[x1][y1];
	board->table[x1][y1] = board->table[x2][y2];
	board->table[x2][y2] = temp;
}