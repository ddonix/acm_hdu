#include<iostream>
#include<cstdio>
using namespace std;

const int JZ = 100000000;
const int L2 = 380;

void HighPreAdd(int *add1, int *add2, int *sum)
{
	int i, j, c = 0;
	i = 0;
	while(1)
	{
		if (add1[i] != -1)
		{
			if (add2[i] != -1)
				sum[i] = add1[i] + add2[i] + c;
			else
				sum[i] = add1[i] + c;
		}
		else if (add2[i] != -1)
			sum[i] = add2[i] + c;
		else 
		{
			if (c)
				sum[i] = c;
			break;
		}
		if (sum[i] >= JZ)
		{
			sum[i] -= JZ;
			c = 1;
		}
		else
		{
			c = 0;
		}
		i++;
	}
}


void HighPreSub1(int sub1[], int sub2[], int sub3[])//高精度减法
{
	int j = 0;
	while (sub1[j]!=-1)//循环到被减数的最高位+1时退出
	{
		sub3[j] = sub2[j]-sub1[j];
		j++;
	}
	for (int n = 0;n < j;n++)
	{
		if (sub3[n] < 0)
		{
			sub3[n + 1]--;
			sub3[n] += JZ;
		}
	}
}

void HighPreSub2(int sub1[], int sub2[])//高精度减法
{
	int j = 0;
	while (sub1[j]!=-1)//循环到被减数的最高位+1时退出
	{
		sub2[j] = sub2[j]-sub1[j];
		j++;
	}
	for (int n = 0;n < j;n++)
	{
		if (sub2[n] < 0)
		{
			sub2[n + 1]--;
			sub2[n] += JZ;
		}
	}
}

int main()
{
	int num,t,count=0, *p;
	int *Add1=new int[L2];//2个操作数；
	int *Add2=new int[L2];
	int *TN = new int[L2];//TN为美观的数量，total一开始为总的排列次数,后为完美排列的次数。
	int *total = new int[L2];
	for (int i = 0;i < L2;i++)
	{
		Add1[i] = -1;
		Add2[i] = -1;
		TN[i] = -1;
		total[i] = -1;
	}
	Add1[0] = 2;
	Add2[0] = 4;
	cin >> num;
	for (int i = 3;i <= num;i++)
	{
		HighPreAdd(Add1, Add2,TN);
		if (i != num ) 
		{
			p = Add1;//元素互换
			Add1 = Add2;
			Add2 = TN;
			TN = p;
		}
	}
	for (int i = 0;i < L2;i++)
	{
		Add1[i] = -1;
		Add2[i] = -1;
	}
	Add1[0] = 2;
	Add2[0] = 2;
	for (int i = 1;i < num;i++)//表示2^n
	{
		HighPreAdd(Add1, Add2, total);
		if (i != num - 1)
		{
			p = Add1;
			Add1 = total;
			Add2 = total;
			total = p;
		}
	}
	HighPreSub(TN, total);//高精度减法
	while (total[count] != -1)//定位total最高8位的下标
		count++;
	count--;
	t = count;
	while ((count + 1) != 0)
	{
		if (t != count)
			printf("%08d", total[count]);
			else 
				printf("%d", total[count]);
		count--;
	}
	return 0;
}
