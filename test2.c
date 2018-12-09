
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int a[10000];

int main()
{
	int i, j,tmp;
	srand(unsigned(time(NULL)));
	for(i=0, j=0;i<10000;i++,j++)
	{
		i = rand() % 10000;
		j = rand() % 10000;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
		return 0;
}
