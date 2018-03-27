#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include <iostream>

using namespace std;

#define INF 100//���ɵ��� 

int pointsum;//�����Ŀ
int data[100][100];
int result[100][100];//������� 
int path[100][100];//·������ 

void init(void)//��ʼ��ͼ������ 
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
        for(j = 1; j< pointsum+1;j++)//��0�к͵�0��û�д������ 
    	{
        	result[i][j] = data[i][j];//�Ȱ�ԭ���ĸ��ƹ�ȥ 
       	 	path[i][j] = -1;//·��ȫΪû�� 
   		}
    for(k = 1; k < pointsum+1; k++)//ѭ��n�����η��� 
        for(i = 1; i< pointsum+1;i++)
            for(j = 1; j< pointsum+1; j++)
           	 	if(result[i][j] > result[i][k] + result[k][j])
        		{
           			result[i][j] = result[i][k] + result[k][j];
            		path[i][j] = k;
        		}
}

void output(int i,int j)//������·�� 
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
	int sum;//ѭ�����ܴ���
	scanf("%d",&sum);
	printf("%d\n",sum);
	for(int i=0;i < sum;i++)
	{
		scanf("%d",&pointsum);//��ȡ��ĸ���
		printf("%d\n",pointsum);
		init();//��ʼ��ͼ 
		for(int j=1;j < pointsum+1;j++)
			for(int k=1;k < pointsum+1;k++)
				 scanf("%d",&data[j][k]);//�õ������ľ���
		Floyd();//���ú���
		for(int i=1;i < pointsum+1;i++)//�����̾������ 
		{
			for(int j=1;j < pointsum+1;j++)
				printf("%d ",result[i][j]);
			printf("\n");
		}
		for(int i=1;i < pointsum+1;i++)//������·��
		{
			for(int j=1;j < pointsum+1;j++)
			{
				if(i == j)
					printf("%d\n",i);
				else
				{
					printf("%d ",j);
					output(j,i);//�����Ӧ�Ľ��
					printf("\n");
				}
					 
			}		
		}				  
	} 
	return 0; 
} 
