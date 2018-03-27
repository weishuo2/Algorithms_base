#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include<algorithm>

using namespace std;
#define MAX 100

struct POINT
{
	double x;
	double y;
}point[MAX];

struct MINs
{
	POINT point1;
	POINT point2;
	double dis;
}mins[MAX];


static int num = 0;//用于计数算出的最小距离
vector<POINT> vecmain;//用于存储输入的点


bool cmpx(POINT & a, POINT& b)//横坐标比较
{
	return a.x < b.x;
}

bool cmpy(POINT & a, POINT& b)//纵坐标比较
{
	return a.y < b.y;
}

double distancea(POINT &a, POINT &b)//计算距离 
{
	return sqrt	((pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

double getmin(vector<POINT>&vec, int low, int high)
{
	if (low + 1 == high)//只有两个点
	{
		mins[num].dis = distancea(vec[low], vec[high]);
		mins[num].point1 = vec[low];
		mins[num].point2 = vec[high];
		++num;
		return distancea(vec[low], vec[high]);
	}
	else if (low + 2 == high)//只有三个点
	{
		double dismin = min (min(distancea(vec[low], vec[low + 1]), distancea(vec[low + 1], vec[high])), distancea(vec[low], vec[high]));//将最近点对的距离以及点的坐标存储
		if (dismin == distancea(vec[low], vec[high]))
		{
			mins[num].dis = dismin;
			mins[num].point1 = vec[low];
			mins[num].point2 = vec[high];
			++num;
		}
		if (dismin== distancea(vec[low], vec[low+1]))
		{
			mins[num].dis = dismin;
			mins[num].point1 = vec[low];
			mins[num].point2 = vec[low+1];
			++num;
		}
		if (dismin == distancea(vec[low+1], vec[high]))
		{
			mins[num].dis = dismin;
			mins[num].point1 = vec[low+1];
			mins[num].point2 = vec[high];
			++num;
		}
		return  min(min(distancea(vec[low], vec[low + 1]), distancea(vec[low + 1], vec[high])), distancea(vec[low], vec[high]));
	}
	else
	{
		int mid = (high + low) / 2;
		double leftmin = getmin(vec, low, mid);
		double rightmin = getmin(vec, mid + 1, high);
		double d = min(leftmin,rightmin);
		vector<POINT>res;
		res.erase(res.begin(), res.end());
		for (int i = low; i <= high; i++)//求与分割线的横坐标距离在d之内的点
		{
			if (fabs(vec[i].x - vec[mid].x) <= d)
				res.push_back(vec[i]);
		}
		sort(res.begin(), res.end(), cmpy);//根据纵坐标进行排序
		for (int i = 0; i < res.size()-1; i++)
		{
			for (int j = i+1; j < res.size(); j++)//求与vec[i]的纵坐标距离在d内的点
			{
				if (res[j].y - res[i].y > d) break;
				else
				{
					double ds = distancea(res[i], res[j]);
					if (ds <= d)
					{
						mins[num].dis = ds;
						mins[num].point1 = res[i];
						mins[num].point2 = res[j];
						++num;
						d = ds;
					}
				}
			}
		}
		return d;
	}
}

int main()
{
	int sum;//总的循环次数 
	int n;
	scanf("%d",&sum);
	for(int jishu=0;jishu < sum;jishu++)
	{
		scanf("%d",&n);//点的个数 
		for (int i = 0; i < n; i++)
		{
			//点的坐标 
			scanf("%lf",&point[i].x);
			scanf("%lf",&point[i].y);
		}
		vecmain.clear();//赋值前先清空 
		for (int i = 0; i < n; i++)
		{
			vecmain.push_back(point[i]);//点的矢量 
		}
		sort(vecmain.begin(), vecmain.end(), cmpx);//x的升序排列 
		double mindis = getmin(vecmain, 0, vecmain.size() - 1);//求出所有点的最小距离 
		vector<MINs> out;
		out.erase(out.begin(), out.end());//置0 
		int num2 = 0;
		for (int i = 0; i < num; i++)//主要是判断最小距离点对中真实的最小点对 
		{
			if (mins[i].dis == mindis)
			{
				int m = 1;
				if (num2 == 0)
				{
					out.push_back(mins[i]);
					++num2;
				}
				else
				{
					for (int j = 0; j < num2; j++)
					{
						if ((mins[i].point1.x == out[j].point1.x && mins[i].point1.y == out[j].point1.y && mins[i].point2.x == out[j].point2.x && mins[i].point2.y == out[j].point2.y) || (mins[i].point1.x == out[j].point2.x && mins[i].point1.y == out[j].point2.y && mins[i].point2.x == out[j].point1.x && mins[i].point2.y == out[j].point1.y)) 
							m = 0;
					}
					if (m == 1)
					{
						out.push_back(mins[i]);
						++num2;
					}
				}
			}
		}
		for (int i = 0; i < num2; i++)
		{
			cout<< out[i].point1.x << " " << out[i].point1.y << " " << out[i].point2.x << " " << out[i].point2.y << " ";
		}
		printf("\n");
	}
	return 0;

}
