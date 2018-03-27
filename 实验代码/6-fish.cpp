#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=30;  
  
int n,h;        //n表湖数目,h表总时间 
int t[maxn];    //t[i]表从i湖走到i+1湖花的单位时间  
int f[maxn];    //初始每单位时间能钓的鱼量  
int d[maxn];    //每单位时间钓鱼量的减少量  
int cf[maxn];   //当前每单位时间能钓的鱼量  
  
int ans;        //总钓鱼量  
int sum[maxn];  //每个湖对应的钓鱼时间  
  
void get_max(int k,int &temp_ans,int *temp_sum)//选[1,k]内的湖,获得当前单位时间的钓鱼量,并更新对应数组  
{  
    int max_v=-1,id=-1;  
    for(int i=1;i <= k;i++)//从前往后选,保证解不唯一时也符合要求  
    	if(cf[i]> max_v)  
    	{  
        	max_v=cf[i];  
        	id=i;  
    	}  
    temp_ans += cf[id];  
    temp_sum[id]++;  
    if(cf[id] > d[id])	
    	cf[id] -=d[id];  
    else
		cf[id] = 0;  
}  
  
int main()  
{  
	scanf("%d",&n);//读取湖泊数 
    while(n != 0)  
    {  
        scanf("%d",&h);  
        h= h*12;  //有h个五分钟 
        ans = 0;  //初始化 
        for(int i=0;i < maxn;i++)
			sum[i]=0;//设置初始化费为0 
        sum[1] = h;//默认当所有f=0时的解  
        for(int i=1;i<=n;i++)  
            scanf("%d",&f[i]);  
        for(int i=1;i<=n;i++)  
            scanf("%d",&d[i]);  
        for(int i=1;i<=n-1;i++)  
            scanf("%d",&t[i]);  //读取数据 
    	for(int i=1;i<=n;i++)   //枚举最后一个钓鱼的湖  
    	{    
        	int path_time = 0;
			for(int j=1;j < i;j++)
				path_time += t[j]; 
 			int fish_time = h - path_time;  //仅用于钓鱼的时间
        	int temp_ans=0;//当前解  
        	int temp_sum[maxn];//当前解  
        	for(int j=0;j < maxn;j++)
        		temp_sum[j] = 0;
        	for(int j=0;j < maxn;j++)//初始化 
        		cf[j]=f[j];
        	for(int j=0;j < fish_time;j++)//关键部分，每一次钓鱼时间取当前可钓的最大的鱼数 
            	get_max(i,temp_ans,temp_sum);   
        	if(temp_ans > ans)//当前解更优 ,与记录的最优解进行交换 
        	{  
            	ans=temp_ans;  
            	for(int jishu=0;jishu < maxn;jishu++)
            		sum[jishu]=temp_sum[jishu];
        	}  
    	}  
    	for(int i=1;i<=n;i++)  
    	{  
        	printf("%d",sum[i]*5);  
        	if(i != n)//最后一次不输出逗号 
        		printf(", ");
    	}  
    	printf("\nNumber of fish expected: %d\n\n",ans);  
    	scanf("%d",&n);//读取湖泊数 
    }  
    return 0;  
}  
