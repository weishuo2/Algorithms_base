#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct point{                      //��ṹ 
	double x,y;
};
double Distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){   //������y���� 
	return a.y<b.y;
}
bool cmp2(point a,point b){  //������x���� 
	return a.x<b.x;
}
double closestPoint(point s[],int low,int high,point rec[])
{
	double d1,d2,d3,d;
	int mid,i,j,index;
	double x1,y1,x2,y2;
	point t1[2],t2[2];
	point P[high-low+1];
	if(high-low==1){//���������� 
		rec[0].x=s[low].x;
		rec[0].y=s[low].y;
		rec[1].x=s[high].x;
		rec[1].y=s[high].y;
		return Distance(s[low],s[high]);
	}
	if(high-low==2){//���������� 
		d1=Distance(s[low],s[low+1]);
		d2=Distance(s[low+1],s[high]);
		d3=Distance(s[low],s[high]);
		if((d1<d2)&&(d1<d3)){
			rec[0].x=s[low].x;
		    rec[0].y=s[low].y;
		    rec[1].x=s[low+1].x;
		    rec[1].y=s[low+1].y;
		    return d1;
		}
		else if((d2<d3)&&(d2<d1)){
			rec[0].x=s[low+1].x;
		    rec[0].y=s[low+1].y;
		    rec[1].x=s[high].x;
		    rec[1].y=s[high].y;
		    return d2;
		}
		else{
			rec[0].x=s[low].x;
		    rec[0].y=s[low].y;
		    rec[1].x=s[high].x;
		    rec[1].y=s[high].y;
		    return d3;
		}
	}
	mid=(low+high)/2;//����3����������
	d1=closestPoint(s,low,mid,rec);
	t1[0]=rec[0];t1[1]=rec[1];
	d2=closestPoint(s,mid+1,high,rec);
	t2[0]=rec[0];t2[1]=rec[1];
	if(d1<d2){
		d=d1;
		rec[0]=t1[0];rec[1]=t1[1];
	}
	else{
		d=d2;
		rec[0]=t2[0];rec[1]=t2[1];
	}
    int	index=0;
    for(i=mid;(i>=low)&&((s[mid].x-s[i].x)<d);i--)//mid����2d��Χ�ĵ㼯 
        P[index++]=s[i];
    for(i=mid+1;(i<=high)&&((s[i].x-s[mid].x)<d);i++)
        P[index++]=s[i];
    sort(P,P+index,cmp)//��y����
	for(i=0;i<index;i++){
		for(j=i+1;j<index;j++){
			if((P[j].y-P[i].y)>=d)
			    break;
			else{
				d3=Distance(P[i],P[j]);
				if(d3<d){
					rec[0]=p[i];
					rec[1]=p[j];
					d=d3;
				}
			}
		}
	} 		
	return d;	
} 

