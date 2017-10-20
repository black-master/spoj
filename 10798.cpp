/**
Online Judge : SPOJ
Problem No   : 10798
Problem Name : WACHOVIA - Wachovia Bank
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.02s
Memory       : 2.9M
Algorithm    : 0/1 Knapsack
*/

#include<bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define maxBags 50
#define maxWeight 1000

using namespace std;

int testCases;
int k,m;
int profit;

int ara[maxBags+1][maxWeight+1];
int value[maxBags+1],weight[maxBags+1];

int Knapsack(int i, int w)
{
    if(i==m+1)
        return 0;

    if(ara[i][w]!=-1)
        return ara[i][w];

    int profit1,profit2;

    if(w+weight[i]<=k)
        profit1 = value[i]+Knapsack(i+1, w+weight[i]);
    else profit1=0;

    profit2 = Knapsack(i+1, w);

    ara[i][w] = max(profit1, profit2);

    return ara[i][w];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCases);

    while(testCases--)
    {
        scanf("%d %d", &k, &m);

        int i;

        for(i=1; i<=m; i++)
            scanf("%d %d", &weight[i], &value[i]);

        mem(ara,-1);

        profit = Knapsack(1,0);

        printf("Hey stupid robber, you can get %d.\n", profit);
    }
    return 0;
}
