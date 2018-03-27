#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void bigplu(int a[],int alen,int b[],int blen);
int compare(int a[],int alen,int b[],int blen);
int bigsub(int a[],int alen,int b[],int blen);
void bigmul(int a[],int alen,int b[],int blen);

int main(void)
{
	int sum;//总的循环次数 
	int yunsuan;//运算类型 
	char a[100],b[100];//原始数据 
	int alen,blen;//两个数的长度
	int afu,bfu;//判断a，b是否为负数
	int aint[100],bint[100];//转化为整数 
	int i,j;
	scanf("%d",&sum);//读取循环次数 
	for(i = 0;i < sum;i++)
	{
		for(j = 0;j<100;j++)//初始化 
		{
			aint[j]=0;
			bint[j]=0;
		}
		scanf("%s",a);//第一个长整数，只能用字符串读
		scanf("%s",b);//第二个长整数
		scanf("%d",&yunsuan);//操作类型 
		alen = strlen(a);//计算长度 
		blen = strlen(b);//a,b的长度 
		for(j = 0;j < alen;j++)//转化为int并调整顺序 
			aint[alen-1-j]=a[j]-'0';
		for(j = 0;j < blen;j++)
			bint[blen-1-j]=b[j]-'0';
		if(aint[alen-1] == ('-' - '0'))//判断是否为负数 
		{
			aint[alen-1] = 0;
			alen--;
			afu = 1; 
		}
		else
			afu = 0;
		if(bint[blen-1] == ('-' - '0'))
		{
			bint[blen-1] = 0;
			blen--;
			bfu = 1;
		}
		else
			bfu = 0;
		switch(yunsuan)
		{
			case 1://加法
				if(afu && bfu)//同为负 
				{
					printf("-");
					bigplu(aint,alen,bint,blen);
				}
				else if((afu == 0) && (bfu == 0))//同为正 
				{
					bigplu(aint,alen,bint,blen);
				} 
				else if((afu == 1) && (bfu == 0))//一正一负 
				{
					bigsub(bint,blen,aint,alen);
				}
				else
				{
					bigsub(aint,alen,bint,blen);
				}
				break;
			case 2://减法
				if(afu && bfu)
				{
					bigsub(bint,blen,aint,alen);//同为负，b-a 
				}
				else if((afu == 0) && (bfu == 0))
				{
					bigsub(aint,alen,bint,blen);
				}
				else if((afu == 1) && (bfu == 0))//一正一负 
				{
					printf("-");
					bigplu(aint,alen,bint,blen);
				}
				else
				{
					bigplu(aint,alen,bint,blen);
				}
				break;
			case 3:
				if((afu && bfu) || ((afu == 0) && (bfu == 0)))
				{
					bigmul(aint,alen,bint,blen); 
				}
				else
				{
					printf("-");
					bigmul(aint,alen,bint,blen); 
				}
				break;
				
		}
	}
	return 0;
}

void bigplu(int a[],int alen,int b[],int blen)//传进去的数组顺序应该是高位在数组高位 
{
	int i,len;
	int c[100];
    len = (alen > blen) ? alen:blen;  //len为较长的一个
    for(i = 0;i < 100; i++)       //将数组清0
        c[i]=0;
    for (i = 0;i < len;i++)        //计算每一位的值
    {
        c[i]+=(a[i]+b[i]);
        if (c[i]>=10)
        {
           c[i]-=10;            //大于10的取个位
           c[i+1]++;            //高位加1
        }
    }
    if (c[len] > 0) 
		len++;               //比原来长了一个数 
    for (i = len-1;i > -1;i--)
        printf("%d",c[i]); //打印结果
    printf("\n");
}

int compare(int a[],int alen,int b[],int blen)//比较ab的大小 
{
	int i;
	if(alen > blen)
		return 1;
	else if(alen < blen) 
		return -1;
	else
	{
		for(i = alen - 1;i > -1;i--)
		{
			if(a[i] < b[i])	
				return -1;
			else if(a[i] > b[i])
				return 1;
			else
				continue;
		}
		return 0;
	}
}

int bigsub(int a[],int alen,int b[],int blen)//传进去的数组顺序应该是高位在数组高位 
{
	int i,len;
	int c[100];
    len=(alen>blen)?alen:blen;  //len为较长的一个
    for(i=0;i<100;i++)       //将数组清0
        c[i]=0;
    if (compare(a,alen,b,blen)==0)        //比较a,b大小
    {
    	printf("0\n");
    	return 0;
	}
    else if(compare(a,alen,b,blen) > 0)
    {
    	for (i = 0;i < len;i++)        //计算每一位的值
    	{
      		c[i]+=(a[i]-b[i]);
       	  	if (c[i]<0)
          	{
          		c[i]+=10;            //小于0的原位加10
           		c[i+1]--;            //高位减1
          	}
    	}
	}
    else
    {
    	printf("-");
    	for (i = 0;i < len;i++)        //计算每一位的值
        {
        	c[i]+=(b[i]-a[i]);
       	 	if (c[i]<0)
       	 	{
           		c[i]+=10;            //小于0原位加10
           		c[i+1]--;            //高位减1
        	}
    	}
	}   
    while (len>1 && c[len-1]==0)  //去掉高位的0
        len--;
    for(i = len-1;i> -1;i--)         //打印结果
        printf("%d",c[i]);
    printf("\n");
    return 1;
} 

void bigmul(int a[],int alen,int b[],int blen)//传进去的数组顺序应该是高位在数组高位 
{
	int i,j,len;
	int c[200];
    for (i = 0;i < 200;i++)                  //数组清0
        c[i]=0;
    for (i = 0;i < alen;i++)                  //被乘数循环
      for (j = 0;j < blen;j++)                //乘数循环
         c[i+j]+=a[i]*b[j];              //将每一位计算累加
   len=alen+blen;                          //取最大长度
   for(i=0;i < len;i++)
   {
   	    c[i+1]+=c[i]/10;              //将每一次结果累加到高一位
        c[i]%=10;                     //计算每一次的个位
   }
   while (len>1 && c[len-1]==0)              //去掉高位0
      len--;
   for (i=len-1;i > -1;i--)                    //打印结果
      printf("%d",c[i]);
   printf("\n"); 
}
