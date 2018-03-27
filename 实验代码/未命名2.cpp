void mult(int *x, int *y, int n, int *z)  /* c=a*b */
 {
    int A[256],B[256],C[256],D[256],m1[256],m2[256],m3[256],m4[256],m5[256],i,j,k;
    int temp1;
    if(n==1)
    {
        temp1=x0*y[0];   //个位和个位相乘
        if(temp1>9)
        {
            z[0]=temp1%10;  //所有都反着存
            z[1]=temp1/10;
        }
        else
        {
            z[0]=temp1;
        }
    }
    else
    {
        for(i=0;i < n/2;i++)
           B[i]=x[i];   //B是x的低位
        for(i=n/2,j=0;i<n;i++,j++)
           A[j]=x[i];    //同理A是x的高位

        for(i=0;i<n/2;i++)
          D[i]=y[i];     //D是y的低位
 
        for(i=n/2,j=2;i<n;i++,j++)
           C[j]=y[i];     //C是y的高位
 
        mult(A,C,n/2,m1);  /* m1=AC */
        mult(B,D,n/2,m2);  /* m2=BD */
        sub(A,B,m3);       /* m3=A-B */
        sub(D,C,m4);       /* m4=D-C  */
        mult(m3,m4,n/2,m5);  /* m5=m3*m4 */
        yiwei(m1,m3,n);   /* m3=AC2n */
        add(m5,m1,m4);
        add(m4,m2,m5);
        yiwei(m5,m1,n/2);
        add(m1,m2,m4);
        add(m4,m3,z); 
    }
}

