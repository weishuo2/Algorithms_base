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


static int num = 0;//���ڼ����������С����
vector<POINT> vecmain;//���ڴ洢����ĵ�


bool cmpx(POINT & a, POINT& b)//������Ƚ�
{
	return a.x < b.x;
}

bool cmpy(POINT & a, POINT& b)//������Ƚ�
{
	return a.y < b.y;
}

double distancea(POINT &a, POINT &b)//������� 
{
	return sqrt	((pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

double getmin(vector<POINT>&vec, int low, int high)
{
	if (low + 1 == high)//ֻ��������
	{
		mins[num].dis = distancea(vec[low], vec[high]);
		mins[num].point1 = vec[low];
		mins[num].point2 = vec[high];
		++num;
		return distancea(vec[low], vec[high]);
	}
	else if (low + 2 == high)//ֻ��������
	{
		double dismin = min (min(distancea(vec[low], vec[low + 1]), distancea(vec[low + 1], vec[high])), distancea(vec[low], vec[high]));//�������Եľ����Լ��������洢
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
		for (int i = low; i <= high; i++)//����ָ��ߵĺ����������d֮�ڵĵ�
		{
			if (fabs(vec[i].x - vec[mid].x) <= d)
				res.push_back(vec[i]);
		}
		sort(res.begin(), res.end(), cmpy);//�����������������
		for (int i = 0; i < res.size()-1; i++)
		{
			for (int j = i+1; j < res.size(); j++)//����vec[i]�������������d�ڵĵ�
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
	int sum;//�ܵ�ѭ������ 
	int n;
	scanf("%d",&sum);
	for(int jishu=0;jishu < sum;jishu++)
	{
		scanf("%d",&n);//��ĸ��� 
		for (int i = 0; i < n; i++)
		{
			//������� 
			scanf("%lf",&point[i].x);
			scanf("%lf",&point[i].y);
		}
		vecmain.clear();//��ֵǰ����� 
		for (int i = 0; i < n; i++)
		{
			vecmain.push_back(point[i]);//���ʸ�� 
		}
		sort(vecmain.begin(), vecmain.end(), cmpx);//x���������� 
		double mindis = getmin(vecmain, 0, vecmain.size() - 1);//������е����С���� 
		vector<MINs> out;
		out.erase(out.begin(), out.end());//��0 
		int num2 = 0;
		for (int i = 0; i < num; i++)//��Ҫ���ж���С����������ʵ����С��� 
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
