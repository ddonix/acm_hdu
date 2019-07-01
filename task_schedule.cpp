#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

int n = -1;
int mat[16][16];

unsigned short task_bitmap = 0x0;
unsigned short bitmap[16] = {	0x1,0x2,0x4,0x8,
				0x10,0x20,0x40,0x80,
				0x100,0x200,0x400,0x800,
				0x1000,0x2000,0x4000,0x8000};

int min_temp[16];

struct record
{
	unsigned short t;
	struct record *next;
};

struct record **pr_head = 0;
struct record **pr_tail = 0;
int *pr_min;

int input()
{
	scanf("%d", &n);
	for(int i=0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	for(int i=0; i < n; i++)
	{
		pr_head = new struct record*[n-3];
		pr_tail = new struct record*[n-3];
		pr_min = new int [n-3];
		for(int i =0; i < n-3; i++)
		{
			pr_head[i] = 0;
			pr_tail[i] = 0;
			pr_min[i] = 150000;
		}
	}
}

int res_min = 1000000;
void play(int ok, int cur_v)
{	
	struct record *re;
	if (ok == n)
	{
		if (cur_v < res_min)
			res_min = cur_v;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if (!(task_bitmap & bitmap[i]) && (cur_v+mat[ok][i] < res_min))
		{
			if (ok > 0)
			{
				re = pr_head[ok-1];
				while(re)
				{
					if (re->t == task_bitmap | bitmap[i])
					{
						if(cur_v+mat[ok][i] < pr_min)
						{
							task_bitmap |= bitmap[i];
							play(ok+1, cur_v+mat[ok][i]);
							task_bitmap &= ~bitmap[i];
						}
					}
				}
				if (re)
			}
			else
			{
			
			}
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
