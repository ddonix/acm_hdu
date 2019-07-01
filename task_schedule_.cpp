#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n = -1;
int **mat = 0;

struct record
{
	unsigned short t;
	int v;
	struct record *next;
};
struct record **pr = 0;

unsigned short task_bitmap = 0x0;
const unsigned short bitmap[16] = {	0x1,0x2,0x4,0x8,
					0x10,0x20,0x40,0x80,
					0x100,0x200,0x400,0x800,
					0x1000,0x2000,0x4000,0x8000};


int input()
{
	scanf("%d", &n);
	mat = new int* [n];
	pr = new record* [n-3];

	for(int i=0; i < n; i++)
	{
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
		if (ok >= 20)
		{
			list = pr[ok-2];
			while(list)
			{
				if (task_bitmap == list->t)
					return list->v;
					
				list = list->next;
			};
		}
		for(i = 0; i < n; i++)
		{
			if (!(task_bitmap & bitmap[i]))
			{
				task_bitmap |= bitmap[i];
				temp = mat[ok][i]+play(ok+1);
				task_bitmap &= ~bitmap[i];
				if (temp < res)
					res = temp;
			}
		}
		if (ok >= 20)
		{
			struct record *re = new record;
			re->t = task_bitmap;
			re->v = res;
			re->next = 0;
			
			
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
			if (!(task_bitmap &= bitmap[i]))
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
