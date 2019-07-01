#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

int n = -1;
int mat[16][16];
bool task[16]= {false};

int input()
{
	scanf("%d", &n);
	for(int i=0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
}

int res_min = 1000000;
void play(int ok, int cur_v)
{	
	if (ok == n)
	{
		if (cur_v < res_min)
			res_min = cur_v;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if (task[i]==false && (cur_v+mat[ok][i] < res_min))
		{
			task[i] = true;
			play(ok+1, cur_v+mat[ok][i]);
			task[i] = false;
		}
	}
}

int main(int argc, char **argv)
{
	int res;
	input();
	play(0,0);
	printf("%d\n", res_min);
	return 0;
}
