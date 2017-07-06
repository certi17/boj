
#include <stdio.h>

#define MAX 1001

int m, n;

typedef struct {
	int size;
	int B[MAX];
}TYPE_A;

TYPE_A A[MAX];
int B[MAX];

int chk_A[MAX];

int dfs(int a)
{
	if (chk_A[a] != 0) return 0;

	chk_A[a] = 1;

	for (int i = 1; i <= A[a].size; i++)
	{
		if (B[A[a].B[i]] == 0 || dfs(B[A[a].B[i]]))
		{
			B[A[a].B[i]] = a;
			return 1;
		}
	}

	return 0;
}

int main()
{
	freopen("9576.txt", "r", stdin);
	setbuf(stdout, NULL);

	int s, e, count;

	int total;
	scanf("%d", &total);

	for (int test = 1; test <= total; test++)
	{

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)
			B[i] = 0;

		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &s, &e);
			A[i].size = e - s + 1;
			for (int j = 1; j <= e - s + 1; j++)
				A[i].B[j] = s+j-1;
		}

		count = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)	chk_A[j] = 0;
			count += dfs(i);
		}
		
		printf("%d\n", count);
	}
	printf("my_sol\n");

	

	return 1;
}