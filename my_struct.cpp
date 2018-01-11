#include <stdio.h>
#include <string.h>

#define MAX 2048

typedef struct UserInfo{
	char name[MAX];
	char passwd[MAX];
	int count;
}UserInfo;

UserInfo g_user[MAX];

int main()
{
	strcpy(g_user[0].name, "hello");
	strcpy(g_user[0].passwd, "world");
	g_user[0].count = 0;

	printf("%s: %s \n", g_user[0].name, g_user[0].passwd);

	return 1;
}
