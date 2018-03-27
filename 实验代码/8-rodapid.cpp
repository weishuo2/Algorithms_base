#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 100000000

struct path 
{
    int a,b,c,p,r;//��㣬�յ㣬�м侭�����������ã�ԭʼ���� 
}path[15];

int n, m;//����ͱ��� 
int vis[15];//�߷��ʴ�����¼ 
int ans;//��С���� 

void dfs(int x, int total) //x��ʾ��ǰ���ڵĽ�㣬tot��ʾ�ܻ��� 
{
    if(total >= ans) 
		return;//��ǰ���ô�����С����ֱ�ӷ��� 
    if(x == n) 
	{
        ans = total;//�����Ѿ�ȷ����tot<ans 
        return;
    }
    for(int i = 0; i < m; i++) 
	{
        int b = path[i].b;
        if(path[i].a == x && vis[b] <= 4) 
		{
            vis[b]++;//���ʼ��ʾ���������ʹ� 
            if(vis[path[i].c])//����м�㱻���ʹ��ˣ��÷��ʺ�Ľ�� 
                dfs(b, total+path[i].p);
            else 
				dfs(b, total+path[i].r);
            vis[b]--;//�ڱ����������ٰ������ӻ�ȥ 
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
        ans = INF;//��¼һ���ϴ���� 
        for(int i=0;i < 15;i++)
        	vis[i]=0;//��ʼ�� 
        vis[1] = 1;//��һ��������ʹ��� 
        dfs(1, 0);
        if(ans != INF) 
			printf("%d\n", ans);
        else 
			printf("impossible\n");
    }
    return 0;
}
