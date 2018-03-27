#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void bigadd(char a[], char b[]);//�ӷ�
void bigsub(char a[], char b[]);//����
void bigmul(char a[], char b[]);//�˷�

void add(int a[], int b[], int c[]);
void sub(int a[], int b[], int c[]);
void mov(int a[], int m);
void print(int c[]);
void alignment(int a1[], int b1[]);
void process(int a[], int b[], int c[], int m);
void Divide_Conquer(int a1[], int b1[], int c[]);


int main()
{
	char s1[1000] = { "\0" };//���ڱ����һ��������
	char s2[1000] = { "\0" };//���ڱ���ڶ���������
	char s3; //���ڱ����������
	cout << "�������һ����������a = ";
	cin >> s1;
	cout << "������ڶ�����������b = ";
	cin >> s2;
	cout << "��ѡ��Ҫ���е����㣨+ - *����";
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
	int c[1001];//���ڴ洢������
	if (strlen(a) < strlen(b))
	{
		swap(a, b);
	}
	int m = strlen(a);
	int n = strlen(b);
	int h = 0;//��λ����ʼ����Ϊ0
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
	int c[1000];//���ڴ洢������
	if (strlen(a) > strlen(b))//a�����ݳ��� > b�����ݳ���
	{
		int m = strlen(a);//�ϴ����ݵĳ���
		int n = strlen(b);//��С���ݵĳ���
		int h = 0;//��λ����ʼ����Ϊ0
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
	else if (strlen(a) < strlen(b))//a�����ݳ��� > b�����ݳ���
	{
		swap(a, b);
		int m = strlen(a);//�ϴ����ݵĳ���
		int n = strlen(b);//��С���ݵĳ���
		int h = 0;//��λ����ʼ����Ϊ0
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
				int m = strlen(a);//�ϴ����ݵĳ���
				int n = strlen(b);//��С���ݵĳ���
				int h = 0;//��λ����ʼ����Ϊ0
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
		int m = strlen(a);//�ϴ����ݵĳ���
		int n = strlen(b);//��С���ݵĳ���
		int h = 0;//��λ����ʼ����Ϊ0
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
	a1[0] += a1[1];//a��ʵ�����ݳ���
	for (int i = 2; i <= a1[0] + 1; i++)
	{
		a1[i] = a[strlen(a) - 1 - i + 2] - '0';//�����һλ��ʼ��a�е����ݴ������a1[]�У���2��ʼ
	}
	b1[0] = strlen(b) - 1;
	if (b1[0] == '-') b1[1] = 0;
	else b1[1] = 1;
	b1[0] += b1[1];//b��ʵ�����ݳ���
	for (int i = 2; i <= b1[0] + 1; i++)
	{
		b1[i] = b[strlen(b) - 1 - i + 2] - '0';//�����һλ��ʼ��b�е����ݴ������b1[]�У���2��ʼ
	}
	a1[1] += a1[1] - 1;//������->1;������->(-1);
	b1[1] += b1[1] - 1;//������->1;������->(-1);
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

void mov(int a[], int m)//��λ
{
	for (int i = a[0] + 1; i >= 2; i--)
	{
		a[i + m] = a[i];
	}
	for (int i = 2; i <= m + 1; i++)//����λ��0
	{
		a[i] = 0;
	}
	a[0] += m;
}

void print(int c[])
{
	int i;
	if (c[1] < 0) cout << "-";
	for (i = c[0] + 1; i >= 2; i--)//ȷ����һ����Ϊ0 ������λ��
	{
		if (c[i]) break;
	}
	for (; i >= 2; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

void alignment(int a1[], int b1[])//������λ����2���ݶ���
{
	int len = max(a1[0], b1[0]);//ȡ�������ϴ�����ݳ���
	int temp = 1;
	for (int i = 0; i <=10; i++)
	{
		if (temp >= len) break;
		temp <<= 1;//ÿ������1λ��Ҳ������2��
	}
	a1[0] = temp;
	b1[0] = temp;
}

void process(int a[], int b[], int c[], int m)
{
	if (a[1] > 0)//����a[]�ڴ洢������Ϊ����
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
	if (a1[0] == 1)//1λ�����
	{
		int temp = a1[2] * b1[2];
		c[0] = 1;
		c[2] = temp % 10;//���˻��ĸ�λ���ִ���c[2]
		if (temp >= 10)//1λ����1λ���õ���λ��
		{
			c[0]++;
			c[3] = temp / 10;//���˻���ʮλ���ִ���c[3]
		}
		c[1] = a1[1] * b1[1];
		return;
	}
	
	int div1[1000] = { 0 };
	int div2[1000] = { 0 };
	int div3[1000] = { 0 };
	int div4[1000] = { 0 };//�����������ڴ洢���κ��Сģ������

	int div5[1000] = { 0 };
	int div6[1000] = { 0 };

	int m1[1000] = { 0 };
	int m2[1000] = { 0 };
	int m3[1000] = { 0 };//�����������ڴ洢ÿ�η��κ����������ļ�����

	for (int i = 1; i <= a1[0] / 2 + 1; i++)//��������a1�ĵ�λ�����ִ���div1[]������,���������ű�ʶλ
	{
		div1[i] = a1[i];
	}
	div1[0] = a1[0] / 2;//div1[]�����ڵ����ݴ�С����a1[]�����һ��

	for (int i = a1[0] / 2 + 2; i <= a1[0] + 1; i++)//��������a1�ĸ�λ�����ִ���div2[]������
	{
		div2[i - a1[0] / 2] = a1[i];
	}
	div2[0] = a1[0] / 2;// div2[]�����ڵ����ݴ�С����a1[]�����һ��
	div2[1] = a1[1];//���ƴ�����a1�ķ���λ

	for (int i = 1; i <= b1[0] / 2 + 1; i++)//��������b1�ĵ�λ�����ִ���div3[]������,���������ű�ʶλ
	{
		div3[i] = b1[i];
	}
	div3[0] = b1[0] / 2;//div3[]�����ڵ����ݴ�С����b1[]�����һ��

	for (int i = b1[0] / 2 + 2; i <= b1[0] + 1; i++)//��������b1�ĸ�λ�����ִ���div4[]������
	{
		div4[i - b1[0] / 2] = b1[i];
	}
	div4[0] = b1[0] / 2;// div4[]�����ڵ����ݴ�С����b1[]�����һ��
	div4[1] = b1[1];//���ƴ�����b1�ķ���λ

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
