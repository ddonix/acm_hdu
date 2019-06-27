#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n = -1;
int **mat = 0;

int *list_task = 0;
int *list_man = 0;

int input()
{
	scanf("%d", &n);
	mat = new int* [n];
	list_man = new int [n];
	list_task = new int [n];
	for(int i=0; i < n; i++)
	{
		list_task[i] = list_man[i] = -1;
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
}

int play(int ok)
{	
	int res,ri,temp;
	if (ok != n-1)
	{	
		res = 15000;
		ri = -1;
		for(int i = 0; i < n; i++)
		{
			if (list_task[i] != -1)
			{
				list_man[ok] = i;
				list_task[i] = ok;
				temp = mat[ok][i]+play(ok+1);
				list_man[ok] = -1;
				list_task[i] = -1;
				if (temp < res)
				{
					res = temp;
					ri = i;
				}
			}
		}
		return res;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (list_task[i] != -1)
			{
				return mat[n-1][i];
			}
		}
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


