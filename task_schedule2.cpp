#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n = -1;
int **mat = 0;

struct record
{
	int *p;
	int v;
	struct record *next;
};
struct record **pr = 0;

int *list_task = 0;


int input()
{
	scanf("%d", &n);
	mat = new int* [n];
	pr = new record* [n-3];

	list_task = new int [n];
	for(int i=0; i < n; i++)
	{
		list_task[i] = -1;
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
	for(int i=0; i < n-3; i++)
	{
		pr[i] = 0;
	}
}

int play(int ok)
{	
	int res,temp,i,j;
	struct record *list;
	res = 150000;
	if (ok < n-1)
	{
		if (ok >= 2)
		{
			list = pr[ok-2];
			while(list)
			{
				for (i=0; i < ok; i++)
				{
					if (list_task[list->p[i]] == -1)
						continue;
				}
				if (i == ok)
					return list->v;
					
				list = list->next;
			};
		}
		for(i = 0; i < n; i++)
		{
			if (list_task[i] == -1)
			{
				list_task[i] = ok;
				temp = mat[ok][i]+play(ok+1);
				list_task[i] = -1;
				if (temp < res)
					res = temp;
			}
		}
		if (ok >= 2)
		{
			struct record *re = new record;
			re->p = new int[ok];
			re->next = 0;
			j = 0;
			for(i = 0; i < n; i++)
			{
				if (list_task[i] != -1)
				{
					re->p[j] = i;
					j++;
				}
			}
			re->v = res;
			
			
			if (pr[ok-2] == 0)
				pr[ok-2] = re;
			else
			{
				list = pr[ok-2];
				while(list->next)
				{
					list = list->next;
				};
				list->next = re;
			}
		}
		return res;
	}
	else
	{
		for (i = 0; i < n; i++)
			if (list_task[i] == -1)
				return mat[n-1][i];
	}
	
}

int main(int argc, char **argv)
{
	int res;
	input();
	res = play(0);
	printf("%d", res);
	return 0;
}
