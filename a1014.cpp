#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double e = 2.5;
	int nj = 2;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(int n = 3; n <=9; n++)
	{
		nj *= n;
		e += (double)1/nj;
		printf("%d %.9f\n", n,e);

	}
	return 0;
}
