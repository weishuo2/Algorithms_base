#include <stdio.h>  
#include <string.h>  
#define MOD  100000000  
#define maxn 13  
  
int dp[maxn][1<<maxn];        //ÿ��״̬���Է�������������  
int n, m;  
int sta[maxn];                //�ܲ��ܷ�����״̬  
  
bool check(int x, int y)      //���ͬ����û�����ڵĻ���x��״̬�Ƿ���Դ���  
{   
    return !(x&y);
}  
  
bool checkself(int x)         //���ͬ����û�����ڵ�  
{   
    return (!(x&(x<<1)));
}  
  
int getresult()  
{  
    int num = 1<<m;  
    for (int i = 0; i < num; i++)  //��һ�У�ֻ��Ҫ�жϸ����ϲ��ϸ�  
        if (check(i, sta[1]) && checkself(i))  
            dp[1][i] = 1;  
    for (int i = 2; i <= n; i++)  //�����ÿһ�У����˱�֤�Լ��ϸ񣬻��ÿ���ǰһ�е�����ºϲ��ϸ�  
        for (int j = 0; j < num; j++)   
            if (check(j, sta[i]))                    //sta[i]��ʾi�в��ܴ��ڵ�״̬  
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
                if ((scanf("%d", &t) == 1) && !t)    //��Ϊÿ�п����ֵķ��� 
                    sta[i] += (1<<(m-j));            //����Բ��ܳ��ֵ�״̬�����            
        printf("%d\n", getresult());  
    }  
    return 0;  
}  
