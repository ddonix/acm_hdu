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

struct record **pr_head = 0;
struct record **pr_tail = 0;

unsigned short task_bitmap = 0x0;
unsigned short bitmap[16];

int input()
{
	unsigned short temp = 0x1;
	scanf("%d", &n);
	mat = new int* [n];
	if (n > 3)
	{
		pr_head = new struct record*[n-3];
		pr_tail = new struct record*[n-3];
		for(int i =0; i < n-3; i++)
		{
			pr_head[i] = 0;
			pr_tail[i] = 0;
		}
	}	
	for(int i =0; i < 16; i++)
	{
		bitmap[i] = temp;
		temp = temp<<1;
	}
	task_bitmap = 0x0;
	for(int i=0; i < n; i++)
	{
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
}

int play(int ok)
{	
	int res,temp,i,j=0;
	struct record *list;
	res = 150000;
	if (ok < n-2)
	{
		if (ok >= 2)
		{
			list = pr_head[ok-2];
			while(list)
			{
				if (list->t == task_bitmap)
				{
					return list->v;
				}
				list = list->next;
			};
		}
		for(int i = 0; i < n; i++)
		{
			if ( !(task_bitmap & bitmap[i]))
			{
				task_bitmap |= bitmap[i];
				temp = mat[ok][i]+play(ok+1);
				task_bitmap &= ~bitmap[i];
				if (temp < res)
					res = temp;
			}
		}
		if (ok >= 2)
		{
			struct record *re = new record;
			re->t = task_bitmap;
			re->v = res;
			re->next = 0;
			
			
			if (pr_head[ok-2] == 0)
			{
				pr_head[ok-2] = re;
				pr_tail[ok-2] = re;
			}
			else
			{
				pr_tail[ok-2]->next = re; 
				pr_tail[ok-2] = re;
			}
		}
		return res;
	}
	else
	{
		int a[2][2],j;
		j = 0;
		for (int i = 0; i < n; i++)
		{
			if ( !(task_bitmap & bitmap[i]))
			{
				a[0][j] = mat[n-2][i];
				a[1][j] = mat[n-1][i];
				j++;
			}
		}
		return a[0][0] + a[1][1] > a[0][1] + a[1][0] ?  a[0][1] + a[1][0] : a[0][0] + a[1][1]; 
	}
	
}

int main(int argc, char **argv)
{
	int res;
	input();
	res = play(0);
	printf("%d\n", res);
	return 0;
}
