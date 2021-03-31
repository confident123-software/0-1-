#include<stdio.h>
#include<stdlib.h>
int V[100][100];
int max(int x, int y)
{
    if(x >= y)
        return x;
    else
        return y;
}

int KnapSack(int w[], int v[], int n, int C, int x[])
{
    int i, j;

    for(i = 0; i <= n; i++)
        V[i][0] = 0;
    for(j = 0; j <= C; j++)
        V[0][j] = 0;

    printf("0/1背包求解过程：\n");
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= C; j++)
        {
            if(j < w[i - 1])
            {
                V[i][j] = V[i - 1][j];
                printf("[%d][%d]=%2d  ", i, j, V[i][j]);
            }

            else
            {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i - 1]] + v[i - 1]);
                printf("[%d][%d]=%2d  ", i, j, V[i][j]);
            }
        }
        printf("\n");
    }

    for(j = C, i = n; i >= 1; i--)
    {
        if(V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i - 1];
        }
        else
            x[i] = 0;
    }
    printf("选中的物品是:\n");
    for(i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
    return V[n][C];

}

int main()
{
    int w[15], v[15], x[15];
    int s, n = 5, i, C;

    printf("请输入背包的最大容量:\n");
    scanf("%d", &C);

    printf("输入物品数:\n");
    scanf("%d", &n);

    printf("请分别输入物品的重量:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("请分别输入物品的价值:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    s = KnapSack(w, v, n, C, x);

    printf("最大物品价值为:\n");
    printf("%d\n", s);

    return 0;
}
