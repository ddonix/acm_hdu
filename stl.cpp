#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn=10000;

//sort
bool compare(int a, int b)
{
	return a*a > b*b;
}


int f1()
{
	int n, a[maxn];
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) 
			scanf("%d", &a[i]);
		sort(a, a+n, compare); //排序
		for(int i = 0; i < n; i++) 
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}

//vector
int main(int argc, char **argv)
{
	f1();
}
