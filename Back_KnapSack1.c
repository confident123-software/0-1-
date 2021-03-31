#include<stdio.h>
int c; //背包容量
int n; //物品数
int weight[100]; //存放 n 个物品重量的数组
int price[100]; //存放 n 个物品价值的数组
int currentWeight = 0; //当前重量
int currentPrice = 0; //当前价值
int bestPrice = 0; //当前最优值
int bestAnswer[100]; //当前最优解
int bp = 0;
int bA[100]; //当前最优解
int times = 0;
void Print();
void Backtracking(int i)
{
    times += 1;
    if(i > n)
    {
        Print();
        if(bestPrice > bp)
        {
            bp = bestPrice;
            for(int j = 1; j <= n; j++)
                bA[j] = bestAnswer[j];
        }
        return;
    }
    if(currentWeight + weight[i] <= c)
    {
        //将物品 i 放入背包，搜索左子树
        bestAnswer[i] = 1;
        currentWeight += weight[i];
        bestPrice += price[i];
        Backtracking(i + 1); //完成上面的递归，返回到上一结点，物品 i 不放入背包，准备递归右子树
        currentWeight -= weight[i];
        bestPrice -= price[i];
    }
    bestAnswer[i] = 0;
    Backtracking(i + 1);
}
void Print()
{
    int i;
    printf("\n 路径为 {");
    for(i = 1; i < n; ++i)
        printf("%d,", bestAnswer[i]);
    printf("%d}\t 价值为%d\n", bestAnswer[i], bestPrice);
}
void main()
{
    int i;
    /*输入部分*/
    printf("请输入物品的数量:\n");
    scanf("%d", &n);
    printf("请输入背包的容量:\n");
    scanf("%d", &c);
    printf("请依次输入%d个物品的重量:\n", n);
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    printf("请依次输入%d个物品的价值:\n", n);
    for(i = 1; i <= n; i++)
        scanf("%d", &price[i]);
    printf("各符合条件的路径为：\n");
    Backtracking(1);
    printf("最优解路径为 {");
    for(i = 1; i < n; ++i)
        printf("%d,", bA[i]);
    printf("%d}\t总价值为 %d\n", bA[i], bp);
    printf("\n总共搜索结点数%d\n", times);
}
