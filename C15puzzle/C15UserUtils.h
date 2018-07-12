#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct User{
	char *name;
	int movesCount;
};


User * createUser(char *name)
{
	User *user = (User*)malloc(sizeof(User));
	user->name = name;
	user->movesCount = 0;
	return user;
}



void modifyMoveCountBasedOnProccessInput(User *user, int processInputOutCome)
{
	if (processInputOutCome == 1)
		user->movesCount = user->movesCount + 1;
	else
		return;
}



void printUser(User *user)
{
	printf("\nHey %s , You have played %d Moves ", user->name, user->movesCount);
}