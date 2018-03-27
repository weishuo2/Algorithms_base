#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include<algorithm>
//主要是贪心算法，先将木条进行排序，主要依据重量，由小到大，如果重量相同，则依据长度，由小到大。然后对n根木条进行循环搜索，先取第一个，判断是否切割过，没有切割过就将其置为当前木条，并将切割次数加1.然后进行循环
//循环主要是找出所有没有切割且长度重量均不小于当前木条的，然后将其切割。 
using namespace std;   
struct doll  
{  
    int w,h;  
} p[5000],test;  
bool cmp(struct doll a,struct doll b)  
{  
    if(a.w!=b.w) 
		return a.w<b.w;  
    else 
		return a.h<b.h;  
}  
int flag[5000];
int main()  
{  
    int sum;  
    scanf("%d",&sum);  
    for(int jishu=0;jishu < sum;jishu++)
    {  
        int m;  
        for(int i=0;i < 5000;i++)
        	flag[i]=0;//最开始将flag清0 
        scanf("%d",&m);  
        for(int i=0; i<m; i++)   
            scanf("%d%d",&p[i].w,&p[i].h);  
        sort(p,p+m,cmp); //将点排序 
        int count=0;  
        for(int i=0; i < m; i++)  
        {  
            if(!flag[i])//没有切割过 
            {
            	count++;
            	test.w=p[i].w;
            	test.h=p[i].h;//给出新加入的木条的长和宽 
            	flag[i]=1;
            	for(int j=i+1;j<m;j++)  //把比它长且还没有切割的切割掉 
            	{  
              	    if((!flag[j])&&((test.w <= p[j].w)&&(test.h <= p[j].h)))  
               	    {  
                   		test.w=p[j].w;
            			test.h=p[j].h;  
            			flag[j]=1;
               	    }  
           	    } 
			}
            
        }  
        printf("%d\n",count);  
    }  
    return 0;  
}  
