#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void bigadd(char a[], char b[]);//加法
void bigsub(char a[], char b[]);//减法
void bigmul(char a[], char b[]);//乘法

void add(int a[], int b[], int c[]);
void sub(int a[], int b[], int c[]);
void mov(int a[], int m);
void print(int c[]);
void alignment(int a1[], int b1[]);
void process(int a[], int b[], int c[], int m);
void Divide_Conquer(int a1[], int b1[], int c[]);


int main()
{
	char s1[1000] = { "\0" };//用于保存第一个运算数
	char s2[1000] = { "\0" };//用于保存第二个运算数
	char s3; //用于保存运算符号
	cout << "请输入第一个大整数：a = ";
	cin >> s1;
	cout << "请输入第二个大整数：b = ";
	cin >> s2;
	cout << "请选择要进行的运算（+ - *）：";
	cin >> s3;

	switch (s3) {
	    case '+':
		    bigadd(s1,s2);
			break;
		case '-':
			bigsub(s1,s2);
			break;
		case '*':
			bigmul(s1,s2);
			break;

	}
	system("pause");
	return 0;

}

void bigadd(char a[], char b[])
{
	int c[1001];//用于存储输出结果
	if (strlen(a) < strlen(b))
	{
		swap(a, b);
	}
	int m = strlen(a);
	int n = strlen(b);
	int h = 0;//进位，初始设置为0
	int i;
	for (i = 0; i < strlen(b); i++)
	{
		c[i] = (((int)(a[m-1]) - 48) + ((int)(b[n-1]) - 48) + h) % 10;
		h = (((int)(a[m-1]) - 48) + ((int)(b[n-1]) - 48) + h)/ 10;
		m--;
		n--;
	}
	int k = strlen(a) - strlen(b);
	for (i= strlen(b); i <strlen(a); i++)
	{
		c[i] = ((int)(a[k-1]) - 48 + h) % 10;
		h = ((int)(a[k-1]) - 48 + h) / 10;
		k--;
	}
	cout << "a + b = ";
	if (h == 1)
	{
		cout << h;
	}
	for (i = strlen(a)-1; i >=0; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

void bigsub(char a[], char b[])
{
	int c[1000];//用于存储输出结果
	if (strlen(a) > strlen(b))//a的数据长度 > b的数据长度
	{
		int m = strlen(a);//较大数据的长度
		int n = strlen(b);//较小数据的长度
		int h = 0;//借位，初始设置为0
		int i;
		for (i = 0; i < strlen(b); i++)
		{
			if (((int)(a[m - 1])-h) >= (int)b[n - 1])
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h) % 10;
				h = 0;
			}
			else
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h + 10) % 10;
				h = 1;
			}
			m--;
			n--;
		}
		int k = strlen(a) - strlen(b);
		for (i = strlen(b); i < strlen(a); i++)
		{
			c[i] = ((int)(a[k - 1]) - 48 - h) % 10;
			h = 0;
			k--;
		}
		cout << "a - b =";
		for (i = strlen(a) - 1; i >= 0; i--)
		{
			if (c[i] == 0);
			else
			{
				for (int st = i; st >= 0; st--)
				{
					cout << c[st];
				}
				cout << endl;
				return;
			}
		}
	}
	else if (strlen(a) < strlen(b))//a的数据长度 > b的数据长度
	{
		swap(a, b);
		int m = strlen(a);//较大数据的长度
		int n = strlen(b);//较小数据的长度
		int h = 0;//借位，初始设置为0
		int i;
		for (i = 0; i < strlen(b); i++)
		{
			if (((int)(a[m - 1]) - h) >= (int)b[n - 1])
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h) % 10;
				h = 0;
			}
			else
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h + 10) % 10;
				h = 1;
			}
			m--;
			n--;
		}
		int k = strlen(a) - strlen(b);
		for (i = strlen(b); i < strlen(a); i++)
		{
			c[i] = ((int)(a[k - 1]) - 48 - h) % 10;
			h = 0;
			k--;
		}
		cout << "a - b = -";
		for (i = strlen(a) - 1; i >= 0; i--)
		{
			if (c[i] == 0);
			else
			{
				for (int st = i; st >= 0; st--)
				{
					cout << c[st];
				}
				cout << endl;
				return;
			}
		}
	}
	else if (strlen(a) == strlen(b))
	{
		for (int j = 0; j < strlen(a); j++)
		{
			if ((int)(a[j]) < (int)(b[j]))
			{
				swap(a, b);
				int m = strlen(a);//较大数据的长度
				int n = strlen(b);//较小数据的长度
				int h = 0;//借位，初始设置为0
				int i;
				for (i = 0; i < strlen(b); i++)
				{
					if (((int)(a[m - 1]) - h) >= (int)b[n - 1])
					{
						c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h) % 10;
						h = 0;
					}
					else
					{
						c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h + 10) % 10;
						h = 1;
					}
					m--;
					n--;
				}
				cout << "a - b = -";
				for (i = strlen(a) - 1; i >= 0; i--)
				{
					if (c[i] == 0);
					else
					{
						for (int st = i; st >= 0; st--)
						{
							cout << c[st];
						}
						cout << endl;
						return;
					}
				}
			}
		}
		int m = strlen(a);//较大数据的长度
		int n = strlen(b);//较小数据的长度
		int h = 0;//借位，初始设置为0
		int i;
		for (i = 0; i < strlen(b); i++)
		{
			if (((int)(a[m - 1]) - h) >= (int)b[n - 1])
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h) % 10;
				h = 0;
			}
			else
			{
				c[i] = (((int)(a[m - 1]) - 48) - ((int)(b[n - 1]) - 48) - h + 10) % 10;
				h = 1;
			}
			m--;
			n--;
		}
		cout << "a - b =";
		for (i = strlen(a) - 1; i >= 0; i--)
		{
			if (c[i] == 0);
			else
			{
				for (int st = i; st >= 0; st--)
				{
					cout << c[st];
				}
				cout << endl;
				return;
			}
		}
	}
}

void bigmul(char a[], char b[])
{
	int a1[1000] = { 0 };
	int b1[1000] = { 0 }; 
	int c[2000] = { 0 };
	a1[0] = strlen(a) - 1;
	if (a[0] == '-') a1[1] = 0;
	else a1[1] = 1;
	a1[0] += a1[1];//a的实际数据长度
	for (int i = 2; i <= a1[0] + 1; i++)
	{
		a1[i] = a[strlen(a) - 1 - i + 2] - '0';//从最后一位开始将a中的数据存进数组a1[]中，从2开始
	}
	b1[0] = strlen(b) - 1;
	if (b1[0] == '-') b1[1] = 0;
	else b1[1] = 1;
	b1[0] += b1[1];//b的实际数据长度
	for (int i = 2; i <= b1[0] + 1; i++)
	{
		b1[i] = b[strlen(b) - 1 - i + 2] - '0';//从最后一位开始将b中的数据存进数组b1[]中，从2开始
	}
	a1[1] += a1[1] - 1;//正整数->1;负整数->(-1);
	b1[1] += b1[1] - 1;//正整数->1;负整数->(-1);
	alignment(a1, b1);
	Divide_Conquer(a1, b1, c);
	cout << "a * b =";
	print(c);
	return;
}

void add(int a[], int b[], int c[])
{
	int h = 0;
	int len = max(a[0], b[0]);
	for (int i = 2; i <= len + 2; i++)
	{
		c[i] = (a[i] + b[i] + h) % 10;
		h = (a[i] + b[i] + h) / 10;
	}
	c[0] = len + (c[len + 2] > 0);
	c[1] = a[1];
}

void sub(int a[], int b[], int c[])
{
	int h = 0;
	int len = max(a[0], b[0]);
	c[1] = 1;
	for (int i = len + 1; i >= 2; i--)
	{
		if (a[i] > b[i]) break;
	    if (a[i] < b[i])
		{
			swap(a, b);
			c[1] = -1;
			break;
		}
	}
	for (int i = 2; i <= len + 1; i++)
	{
		c[i] = a[i] + h - b[i];
		if (c[i] < 0)
		{
			c[i] = c[i] + 10;
			h = -1;
		}
		else h = 0;
	}
	c[0] = a[0];
}

void mov(int a[], int m)//移位
{
	for (int i = a[0] + 1; i >= 2; i--)
	{
		a[i + m] = a[i];
	}
	for (int i = 2; i <= m + 1; i++)//其余位补0
	{
		a[i] = 0;
	}
	a[0] += m;
}

void print(int c[])
{
	int i;
	if (c[1] < 0) cout << "-";
	for (i = c[0] + 1; i >= 2; i--)//确定第一个不为0 的数的位置
	{
		if (c[i]) break;
	}
	for (; i >= 2; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

void alignment(int a1[], int b1[])//将数据位数以2的幂对齐
{
	int len = max(a1[0], b1[0]);//取两个数较大的数据长度
	int temp = 1;
	for (int i = 0; i <=10; i++)
	{
		if (temp >= len) break;
		temp <<= 1;//每次左移1位，也即乘以2；
	}
	a1[0] = temp;
	b1[0] = temp;
}

void process(int a[], int b[], int c[], int m)
{
	if (a[1] > 0)//数组a[]内存储的数据为正数
	{
		if (b[1] * m > 0)
		{
			add(a, b, c);
		}
		else sub(a, b, c);
	}
	else
	{
		if (b[1] * m > 0)
		{
			sub(b, a, c);
		}
		else add(a, b, c);
	}
}

void Divide_Conquer(int a1[], int b1[], int c[])
{
	if (a1[0] == 1)//1位数相乘
	{
		int temp = a1[2] * b1[2];
		c[0] = 1;
		c[2] = temp % 10;//将乘积的个位数字存在c[2]
		if (temp >= 10)//1位数乘1位数得到两位数
		{
			c[0]++;
			c[3] = temp / 10;//将乘积的十位数字存在c[3]
		}
		c[1] = a1[1] * b1[1];
		return;
	}
	
	int div1[1000] = { 0 };
	int div2[1000] = { 0 };
	int div3[1000] = { 0 };
	int div4[1000] = { 0 };//申请数组用于存储分治后的小模块数组

	int div5[1000] = { 0 };
	int div6[1000] = { 0 };

	int m1[1000] = { 0 };
	int m2[1000] = { 0 };
	int m3[1000] = { 0 };//申请数组用于存储每次分治后的两个数组的计算结果

	for (int i = 1; i <= a1[0] / 2 + 1; i++)//将大整数a1的低位数部分存入div1[]数组中,包括正负号标识位
	{
		div1[i] = a1[i];
	}
	div1[0] = a1[0] / 2;//div1[]数组内的数据大小等于a1[]数组的一半

	for (int i = a1[0] / 2 + 2; i <= a1[0] + 1; i++)//将大整数a1的高位数部分存入div2[]数组中
	{
		div2[i - a1[0] / 2] = a1[i];
	}
	div2[0] = a1[0] / 2;// div2[]数组内的数据大小等于a1[]数组的一半
	div2[1] = a1[1];//复制大整数a1的符号位

	for (int i = 1; i <= b1[0] / 2 + 1; i++)//将大整数b1的低位数部分存入div3[]数组中,包括正负号标识位
	{
		div3[i] = b1[i];
	}
	div3[0] = b1[0] / 2;//div3[]数组内的数据大小等于b1[]数组的一半

	for (int i = b1[0] / 2 + 2; i <= b1[0] + 1; i++)//将大整数b1的高位数部分存入div4[]数组中
	{
		div4[i - b1[0] / 2] = b1[i];
	}
	div4[0] = b1[0] / 2;// div4[]数组内的数据大小等于b1[]数组的一半
	div4[1] = b1[1];//复制大整数b1的符号位

	process(div2, div1, div5, -1);
	process(div3, div4, div6, -1);
	Divide_Conquer(div2, div4, m1);
	Divide_Conquer(div5, div6, m2);
	Divide_Conquer(div1, div3, m3);
	process(m1, m2, div5, 1);
	process(div5, m3, div6, 1);
	mov(m1, a1[0]);
	mov(div6, a1[0] / 2);
	process(m1, div6, div5, 1);
	process(div5, m3, c, 1);
}
