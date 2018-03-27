#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include <iostream>

using namespace std;

#define INF 100//不可到达 

int pointsum;//点的数目
int data[100][100];
int result[100][100];//结果数组 
int path[100][100];//路径数组 

void init(void)//初始化图的数组 
{
	for(int i=0;i < pointsum;i++)
		for(int j;j < pointsum;j++)
			if(i == j)
				data[i][j] = 0;
			else
				data[i][j] = INF;
} 

void Floyd(void)
{
    int i,j,k;
    for(i = 1 ;i < pointsum+1; i++)
        for(j = 1; j< pointsum+1;j++)//第0行和第0列没有存放数据 
    	{
        	result[i][j] = data[i][j];//先把原本的复制过去 
       	 	path[i][j] = -1;//路径全为没有 
   		}
    for(k = 1; k < pointsum+1; k++)//循环n的三次方次 
        for(i = 1; i< pointsum+1;i++)
            for(j = 1; j< pointsum+1; j++)
           	 	if(result[i][j] > result[i][k] + result[k][j])
        		{
           			result[i][j] = result[i][k] + result[k][j];
            		path[i][j] = k;
        		}
}

void output(int i,int j)//输出最短路径 
{
    if(path[i][j]==-1)
    	printf("%d ",j);
    else
	{
        output(i,path[i][j]);
        output(path[i][j],j);
    }
}

int main(void)
{
	int sum;//循环的总次数
	scanf("%d",&sum);
	printf("%d\n",sum);
	for(int i=0;i < sum;i++)
	{
		scanf("%d",&pointsum);//读取点的个数
		printf("%d\n",pointsum);
		init();//初始化图 
		for(int j=1;j < pointsum+1;j++)
			for(int k=1;k < pointsum+1;k++)
				 scanf("%d",&data[j][k]);//得到顶点间的距离
		Floyd();//调用函数
		for(int i=1;i < pointsum+1;i++)//输出最短距离矩阵 
		{
			for(int j=1;j < pointsum+1;j++)
				printf("%d ",result[i][j]);
			printf("\n");
		}
		for(int i=1;i < pointsum+1;i++)//输出最短路径
		{
			for(int j=1;j < pointsum+1;j++)
			{
				if(i == j)
					printf("%d\n",i);
				else
				{
					printf("%d ",j);
					output(j,i);//输出对应的结果
					printf("\n");
				}
					 
			}		
		}				  
	} 
	return 0; 
} 
