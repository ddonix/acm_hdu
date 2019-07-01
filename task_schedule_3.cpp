#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 16
int vist[MAX];
int d[MAX][MAX];
int n;
int minp=1000000;

void dfs(int cur,int curp)
{
	if(cur==n)
	{
	   if(curp<minp)
	   	minp=curp;
	   return;
	}
	for(int i=0;i<n;i++)
	{
		if(vist[i]==false&&d[cur][i]+curp<minp)
		{
			vist[i]=true;
			dfs(cur+1,d[cur][i]+curp);
			vist[i]=false;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	 {
	 	scanf("%d", &d[i][j]);
 	 }
 	dfs(0,0); 
 	cout<<minp<<endl;
}
