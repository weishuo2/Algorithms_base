#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 100000000

struct path 
{
    int a,b,c,p,r;//起点，终点，中间经过，经过费用，原始费用 
}path[15];

int n, m;//顶点和边数 
int vis[15];//边访问次数记录 
int ans;//最小费用 

void dfs(int x, int total) //x表示当前所在的结点，tot表示总花费 
{
    if(total >= ans) 
		return;//当前费用大于最小费用直接返回 
    if(x == n) 
	{
        ans = total;//这里已经确保了tot<ans 
        return;
    }
    for(int i = 0; i < m; i++) 
	{
        int b = path[i].b;
        if(path[i].a == x && vis[b] <= 4) 
		{
            vis[b]++;//在最开始表示这个顶点访问过 
            if(vis[path[i].c])//如果中间点被访问过了，用访问后的结果 
                dfs(b, total+path[i].p);
            else 
				dfs(b, total+path[i].r);
            vis[b]--;//在遍历结束后再把这个点加回去 
        }
    }
}

int main() 
{
    while(scanf("%d%d",&n,&m) != EOF) 
	{
        for(int i = 0; i < m; i++)
        { 
        	scanf("%d",&path[i].a);
        	scanf("%d",&path[i].b);
        	scanf("%d",&path[i].c);
        	scanf("%d",&path[i].p);
        	scanf("%d",&path[i].r);
    	}
        ans = INF;//记录一个较大的数 
        for(int i=0;i < 15;i++)
        	vis[i]=0;//初始化 
        vis[1] = 1;//第一个顶点访问过了 
        dfs(1, 0);
        if(ans != INF) 
			printf("%d\n", ans);
        else 
			printf("impossible\n");
    }
    return 0;
}
