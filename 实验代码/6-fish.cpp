#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=30;  
  
int n,h;        //n�����Ŀ,h����ʱ�� 
int t[maxn];    //t[i]���i���ߵ�i+1�����ĵ�λʱ��  
int f[maxn];    //��ʼÿ��λʱ���ܵ�������  
int d[maxn];    //ÿ��λʱ��������ļ�����  
int cf[maxn];   //��ǰÿ��λʱ���ܵ�������  
  
int ans;        //�ܵ�����  
int sum[maxn];  //ÿ������Ӧ�ĵ���ʱ��  
  
void get_max(int k,int &temp_ans,int *temp_sum)//ѡ[1,k]�ڵĺ�,��õ�ǰ��λʱ��ĵ�����,�����¶�Ӧ����  
{  
    int max_v=-1,id=-1;  
    for(int i=1;i <= k;i++)//��ǰ����ѡ,��֤�ⲻΨһʱҲ����Ҫ��  
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
	scanf("%d",&n);//��ȡ������ 
    while(n != 0)  
    {  
        scanf("%d",&h);  
        h= h*12;  //��h������� 
        ans = 0;  //��ʼ�� 
        for(int i=0;i < maxn;i++)
			sum[i]=0;//���ó�ʼ����Ϊ0 
        sum[1] = h;//Ĭ�ϵ�����f=0ʱ�Ľ�  
        for(int i=1;i<=n;i++)  
            scanf("%d",&f[i]);  
        for(int i=1;i<=n;i++)  
            scanf("%d",&d[i]);  
        for(int i=1;i<=n-1;i++)  
            scanf("%d",&t[i]);  //��ȡ���� 
    	for(int i=1;i<=n;i++)   //ö�����һ������ĺ�  
    	{    
        	int path_time = 0;
			for(int j=1;j < i;j++)
				path_time += t[j]; 
 			int fish_time = h - path_time;  //�����ڵ����ʱ��
        	int temp_ans=0;//��ǰ��  
        	int temp_sum[maxn];//��ǰ��  
        	for(int j=0;j < maxn;j++)
        		temp_sum[j] = 0;
        	for(int j=0;j < maxn;j++)//��ʼ�� 
        		cf[j]=f[j];
        	for(int j=0;j < fish_time;j++)//�ؼ����֣�ÿһ�ε���ʱ��ȡ��ǰ�ɵ����������� 
            	get_max(i,temp_ans,temp_sum);   
        	if(temp_ans > ans)//��ǰ����� ,���¼�����Ž���н��� 
        	{  
            	ans=temp_ans;  
            	for(int jishu=0;jishu < maxn;jishu++)
            		sum[jishu]=temp_sum[jishu];
        	}  
    	}  
    	for(int i=1;i<=n;i++)  
    	{  
        	printf("%d",sum[i]*5);  
        	if(i != n)//���һ�β�������� 
        		printf(", ");
    	}  
    	printf("\nNumber of fish expected: %d\n\n",ans);  
    	scanf("%d",&n);//��ȡ������ 
    }  
    return 0;  
}  
