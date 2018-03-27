#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include<algorithm>

using namespace std;
#define MAX 100
#define INF 1000000000


struct POINT
{
	double x;
	double y;
}point[MAX];

struct MINs
{
	POINT point1;
	POINT point2;
}mins[MAX];

double distancea(POINT &a, POINT &b)//计算距离 
{
	return sqrt	((pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

int main()
{
	int sum;//总的循环次数 
	double mindis;//最小距离 
	int minnum;
	int n;
	scanf("%d",&sum);
	for(int jishu=0;jishu < sum;jishu++)
	{
		scanf("%d",&n);//点的个数 
		mindis = INF;
		minnum = 0;
		for (int i = 0; i < n; i++)
		{
			//点的坐标 
			scanf("%lf",&point[i].x);
			scanf("%lf",&point[i].y);
		}
		for(int i1=0;i1 < n;i1++) 
		{
			for(int i2=0;i2 < n;i2++)
			{
				if(i1 != i2)
				{
					if(distancea(point[i1],point[i2]) < mindis)
					{
						mins[0].point1 = point[i1];
						mins[0].point2 = point[i2];
						mindis = distancea(point[i1],point[i2]);
						minnum = 1;		
					}
					else if(distancea(point[i1],point[i2]) == mindis)
					{
						mins[minnum].point1 = point[i1];
						mins[minnum].point2 = point[i2];
						minnum++;
					}
				}
			
			}
		}
		for(int k=0;k < minnum;k++)
		{
			int flag = 1;
			for(int j=0;j < k;j++)
				if((mins[k].point1.x == mins[j].point1.x && mins[k].point1.y == mins[j].point1.y && mins[k].point2.x == mins[j].point2.x && mins[k].point2.y == mins[j].point2.y)|| (mins[k].point1.x == mins[j].point2.x && mins[k].point1.y == mins[j].point2.y && mins[k].point2.x == mins[j].point1.x && mins[k].point2.y == mins[j].point1.y))
					flag = 0;
			if(flag)
				cout<< mins[k].point1.x << " " << mins[k].point1.y << " " << mins[k].point2.x << " " << mins[k].point2.y << " ";
		}
		printf("\n");
		
	}
	return 0;
} 
