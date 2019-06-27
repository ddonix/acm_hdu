#include<cstdio>
#include<cmath>

int f1()
{
	const double pi = acos(-1.0);
	double r, h, s1, s2, s;
	scanf("%lf%lf", &r, &h);
	s1 = pi*r*r;
	s2 = 2*pi*r*h;
	s = s1*2.0 + s2;
	printf("Area = %.3f\n", s);
	printf("pi = %.12f\n", pi);
	return 0;
}

int f2()
{
	int a;
	char str[100];
	scanf("%d  a   %s", &a, str);
	printf("%d %s\n", a, str);
}

int f3()
{
	double a,b,c,d;
	a=sqrt(-1);
	b=a+1;
	c=0.0/0.0;
	d=1/0.0;
	printf("%f %f %f %f\n", a, b, c, d);
}

int n;
int **mat;
int *list;

int f4()
{
	scanf("%d", &n);
	mat = new int* [n];
	list = new int [n];
	for(int i=0; i < n; i++)
	{
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}

}

int play(int ok)
{	
	int res,ri,t;
	ri = -1;
	res = 150000;
	if (ok == 0)
	{
		for (int i = 0; i < n; i++)
		{
			list[0] = i;
			t = mat[0][i]+play(1);
			if (t < res)
			{
				res = t;
				ri = i;
			}
		}
		return res;
	}
	
}

int main(int argc, char **argv)
{
	int res;
	f4();
	res = play(0);
	printf("%d", res);
	return 0;
}


