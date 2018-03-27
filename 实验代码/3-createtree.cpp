#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int data[100][100];
void create_tree(int i,int j,int flag);//flag用来确定是不是第一次运算 

int main(void)
{
	int sum;//总的行列数 
	int i,j;
	scanf("%d",&sum);
	for(i = 0;i < sum;i++)//第0行和第0列全赋值为0，便于从第一行开始进行赋值 
	{
		data[0][i] = 0;
		data[i][0] = 0;
	}
	for(i = 1;i <= sum;i++)
		for(j = 1;j <= sum;j++)
			scanf("%d",&data[i][j]);
	create_tree(1,sum,1);
}

void create_tree(int i,int j,int flag)
{
	if(i <= j)
	{
		if(flag == 1)
		{
			printf("k%d是根\n",data[i][j]);
		}
		else if(flag == 0)
		{
			printf("k%d是k%d的左孩子\n",data[i][j],j+1);
		}
		else
		{
			printf("k%d是k%d的右孩子\n",data[i][j],i-1);
		}
		create_tree(i,data[i][j]-1,0);
		create_tree(data[i][j]+1,j,2);
	}
	else if(j == (i-1))
	{
		if(flag == 0)
		{
			printf("d%d是k%d的左孩子\n",j,j+1);
		}
		else if(flag == 2)
		{
			printf("d%d是k%d的右孩子\n",j,i-1);
		}
	}
}
