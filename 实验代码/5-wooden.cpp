#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include<algorithm>
//��Ҫ��̰���㷨���Ƚ�ľ������������Ҫ������������С�������������ͬ�������ݳ��ȣ���С����Ȼ���n��ľ������ѭ����������ȡ��һ�����ж��Ƿ��и����û���и���ͽ�����Ϊ��ǰľ���������и������1.Ȼ�����ѭ��
//ѭ����Ҫ���ҳ�����û���и��ҳ�����������С�ڵ�ǰľ���ģ�Ȼ�����и 
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
        	flag[i]=0;//�ʼ��flag��0 
        scanf("%d",&m);  
        for(int i=0; i<m; i++)   
            scanf("%d%d",&p[i].w,&p[i].h);  
        sort(p,p+m,cmp); //�������� 
        int count=0;  
        for(int i=0; i < m; i++)  
        {  
            if(!flag[i])//û���и�� 
            {
            	count++;
            	test.w=p[i].w;
            	test.h=p[i].h;//�����¼����ľ���ĳ��Ϳ� 
            	flag[i]=1;
            	for(int j=i+1;j<m;j++)  //�ѱ������һ�û���и���и�� 
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
