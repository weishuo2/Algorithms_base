#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void bigplu(int a[],int alen,int b[],int blen);
int compare(int a[],int alen,int b[],int blen);
int bigsub(int a[],int alen,int b[],int blen);
void bigmul(int a[],int alen,int b[],int blen);

int main(void)
{
	int sum;//�ܵ�ѭ������ 
	int yunsuan;//�������� 
	char a[100],b[100];//ԭʼ���� 
	int alen,blen;//�������ĳ���
	int afu,bfu;//�ж�a��b�Ƿ�Ϊ����
	int aint[100],bint[100];//ת��Ϊ���� 
	int i,j;
	scanf("%d",&sum);//��ȡѭ������ 
	for(i = 0;i < sum;i++)
	{
		for(j = 0;j<100;j++)//��ʼ�� 
		{
			aint[j]=0;
			bint[j]=0;
		}
		scanf("%s",a);//��һ����������ֻ�����ַ�����
		scanf("%s",b);//�ڶ���������
		scanf("%d",&yunsuan);//�������� 
		alen = strlen(a);//���㳤�� 
		blen = strlen(b);//a,b�ĳ��� 
		for(j = 0;j < alen;j++)//ת��Ϊint������˳�� 
			aint[alen-1-j]=a[j]-'0';
		for(j = 0;j < blen;j++)
			bint[blen-1-j]=b[j]-'0';
		if(aint[alen-1] == ('-' - '0'))//�ж��Ƿ�Ϊ���� 
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
			case 1://�ӷ�
				if(afu && bfu)//ͬΪ�� 
				{
					printf("-");
					bigplu(aint,alen,bint,blen);
				}
				else if((afu == 0) && (bfu == 0))//ͬΪ�� 
				{
					bigplu(aint,alen,bint,blen);
				} 
				else if((afu == 1) && (bfu == 0))//һ��һ�� 
				{
					bigsub(bint,blen,aint,alen);
				}
				else
				{
					bigsub(aint,alen,bint,blen);
				}
				break;
			case 2://����
				if(afu && bfu)
				{
					bigsub(bint,blen,aint,alen);//ͬΪ����b-a 
				}
				else if((afu == 0) && (bfu == 0))
				{
					bigsub(aint,alen,bint,blen);
				}
				else if((afu == 1) && (bfu == 0))//һ��һ�� 
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

void bigplu(int a[],int alen,int b[],int blen)//����ȥ������˳��Ӧ���Ǹ�λ�������λ 
{
	int i,len;
	int c[100];
    len = (alen > blen) ? alen:blen;  //lenΪ�ϳ���һ��
    for(i = 0;i < 100; i++)       //��������0
        c[i]=0;
    for (i = 0;i < len;i++)        //����ÿһλ��ֵ
    {
        c[i]+=(a[i]+b[i]);
        if (c[i]>=10)
        {
           c[i]-=10;            //����10��ȡ��λ
           c[i+1]++;            //��λ��1
        }
    }
    if (c[len] > 0) 
		len++;               //��ԭ������һ���� 
    for (i = len-1;i > -1;i--)
        printf("%d",c[i]); //��ӡ���
    printf("\n");
}

int compare(int a[],int alen,int b[],int blen)//�Ƚ�ab�Ĵ�С 
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

int bigsub(int a[],int alen,int b[],int blen)//����ȥ������˳��Ӧ���Ǹ�λ�������λ 
{
	int i,len;
	int c[100];
    len=(alen>blen)?alen:blen;  //lenΪ�ϳ���һ��
    for(i=0;i<100;i++)       //��������0
        c[i]=0;
    if (compare(a,alen,b,blen)==0)        //�Ƚ�a,b��С
    {
    	printf("0\n");
    	return 0;
	}
    else if(compare(a,alen,b,blen) > 0)
    {
    	for (i = 0;i < len;i++)        //����ÿһλ��ֵ
    	{
      		c[i]+=(a[i]-b[i]);
       	  	if (c[i]<0)
          	{
          		c[i]+=10;            //С��0��ԭλ��10
           		c[i+1]--;            //��λ��1
          	}
    	}
	}
    else
    {
    	printf("-");
    	for (i = 0;i < len;i++)        //����ÿһλ��ֵ
        {
        	c[i]+=(b[i]-a[i]);
       	 	if (c[i]<0)
       	 	{
           		c[i]+=10;            //С��0ԭλ��10
           		c[i+1]--;            //��λ��1
        	}
    	}
	}   
    while (len>1 && c[len-1]==0)  //ȥ����λ��0
        len--;
    for(i = len-1;i> -1;i--)         //��ӡ���
        printf("%d",c[i]);
    printf("\n");
    return 1;
} 

void bigmul(int a[],int alen,int b[],int blen)//����ȥ������˳��Ӧ���Ǹ�λ�������λ 
{
	int i,j,len;
	int c[200];
    for (i = 0;i < 200;i++)                  //������0
        c[i]=0;
    for (i = 0;i < alen;i++)                  //������ѭ��
      for (j = 0;j < blen;j++)                //����ѭ��
         c[i+j]+=a[i]*b[j];              //��ÿһλ�����ۼ�
   len=alen+blen;                          //ȡ��󳤶�
   for(i=0;i < len;i++)
   {
   	    c[i+1]+=c[i]/10;              //��ÿһ�ν���ۼӵ���һλ
        c[i]%=10;                     //����ÿһ�εĸ�λ
   }
   while (len>1 && c[len-1]==0)              //ȥ����λ0
      len--;
   for (i=len-1;i > -1;i--)                    //��ӡ���
      printf("%d",c[i]);
   printf("\n"); 
}
