#include <stdio.h>
#include <string.h>

#define MAX 1024

static char gMEM[MAX];

typedef struct {
	char *name;
	int age;
}USER;

USER g_user[MAX];
int g_total;

int init(char *input, int age)
{
	static int pos=0;
	static int count = 0;
	strcpy(&gMEM[pos],input);
		
	g_user[count].name = &gMEM[pos];
	g_user[count].age = age;

	pos += strlen(input);
	gMEM[pos++] = '\0';
	g_total=count++;

	return 1;
}

int show()
{
	for (int i = 0; i <= g_total; i++)
	{
		printf("%s %d\n", g_user[i].name, g_user[i].age);
	}

	return 1;
}

int main()
{
	init("myungkyu_choi",40);
	init("dongrim_yuk", 40);
	init("jinmok_choi", 14);

	show();

	return 1;
}
