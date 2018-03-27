#include <stdio.h>  
#include <string.h>  
#define MOD  100000000  
#define maxn 13  
  
int dp[maxn][1<<maxn];        //每个状态可以放牧方法的总数  
int n, m;  
int sta[maxn];                //能不能放牧的状态  
  
bool check(int x, int y)      //检查同列有没有相邻的或者x的状态是否可以存在  
{   
    return !(x&y);
}  
  
bool checkself(int x)         //检查同行有没有相邻的  
{   
    return (!(x&(x<<1)));
}  
  
int getresult()  
{  
    int num = 1<<m;  
    for (int i = 0; i < num; i++)  //第一行，只需要判断该数合不合格  
        if (check(i, sta[1]) && checkself(i))  
            dp[1][i] = 1;  
    for (int i = 2; i <= n; i++)  //后面的每一行，除了保证自己合格，还得看在前一行的情况下合不合格  
        for (int j = 0; j < num; j++)   
            if (check(j, sta[i]))                    //sta[i]表示i行不能存在的状态  
            	for (int k = 0; k < num; k++)    
                	if (check(k, j) && checkself(j) && checkself(k) && dp[i-1][k])  
                    	dp[i][j] += (dp[i-1][k]%MOD);  
    int ans = 0;  
    for (int i = 0; i < num; i++)  
        ans += (dp[n][i]%MOD);   
    return ans%MOD;  
}  
  
int main()  
{  
    int t;  
    while (scanf("%d %d", &n, &m) != EOF)  
    {  
        memset(dp, 0, sizeof(dp));  
        for (int i = 1; i <= n; i++)  
            for (int j = 1; j <= m; j++)  
                if ((scanf("%d", &t) == 1) && !t)    //即为每行可以种的反码 
                    sta[i] += (1<<(m-j));            //这里对不能出现的状态做标记            
        printf("%d\n", getresult());  
    }  
    return 0;  
}  
