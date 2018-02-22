#include<stdio.h>
#include<stdlib.h>
void sort(int c[5][3])//此函数用于将请求以时间顺序排序，若时间相同按楼层由低到高排序。 
{
	int i,j,c0,c1,c2;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(c[i][0]>c[j][0])
			{	
				c0=c[j][0];
				c1=c[j][1];
				c2=c[j][2];
				c[j][0]=c[i][0];
				c[j][1]=c[i][1];
				c[j][2]=c[i][2];
				c[i][0]=c0;
				c[i][1]=c1;
				c[i][2]=c2; 
			}
			else if(c[i][0]==c[j][0]&&c[i][1]>c[j][1])
			{
				c0=c[j][0];
				c1=c[j][1];
				c2=c[j][2];
				c[j][0]=c[i][0];
				c[j][1]=c[i][1];
				c[j][2]=c[i][2];
				c[i][0]=c0;
				c[i][1]=c1;
				c[i][2]=c2;
			} 
		}
	}
}
int main()
{
	FILE *fp1,*fp2;
	int a[5][3],T=0,floor=1,i,j,t[5],sum;
    fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	if((fp1=fopen("input.txt","r"))==NULL)
    {
   		printf("cannot open this file\n");
   		exit(0);
	} 
	for(i=0;i<5;i++)
	{
		fscanf(fp1,"%d%d%d",&a[i][0],&a[i][1],&a[i][2]);//输入五组请求。
		t[i]=a[i][0];
	}
	for(i=0;i<5;)
	{
		if(T>=a[i][0])
		{
			for(;;)
			{
				if(floor>a[i][1])
				{
					floor--;
					T++;
				}
				else if(floor<a[i][1])
				{
					floor++;
					T++;
				}
				else
				{
					fprintf(fp2,"%d时，在%d楼停靠\n",T,floor);//乘客进电梯 
					T++;
					break;
				}
			}
			for(;;)
			{
				if(floor>a[i][2])
				{
					floor--;
					T++;
				}
				else if(floor<a[i][2])
				{
					floor++;
					T++;
				}
				else
				{
					fprintf(fp2,"%d时，在%d楼停靠\n",T,floor);//乘客出电梯 
					t[i]=T-t[i];
					T++;
					break;
				}
			}
			i++;
		}
		else
		{
			T++;
		}
	}
	sum=t[0]+t[1]+t[2]+t[3]+t[4];
	fprintf(fp2,"%d",sum);
	return 0;
}
