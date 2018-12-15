#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int a[N][N];
int b[N][N];
int c[N][N];

int MM1(int a[][N], int b[][N], int c[][N])
{

    int i = 0, j = 0, k = 0;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

    return 0;
}

int init(int a[][N], int b[][N], int c[][N])
{
    int i, j;
    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            a[i][j] = (rand() % 100);
            b[i][j] = (rand() % 100);
            c[i][j] = 0;
        }
    return 0;
}

void display(int a[][N])
{
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    init(a, b, c);

    MM1(a, b, c);
    display(a);
    display(b);
    display(c);

    getchar();
    return 0;
}