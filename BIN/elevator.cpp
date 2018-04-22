#include<iostream>
#include<fstream>
#include "elevator.h"
using namespace std;
queue::queue()
{
	int i;
	for(i=0;i<3;i++)
	{
		floor[i]=0;
	}
	n=0;
}
wait::wait()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			floor[i][j]=0;
		}
	}
}
Elevatorscheduling::Elevatorscheduling()
{
	currentfloor=0;
	indicator=0;
	people=0;
	t=0;
}
void Elevatorscheduling::gotofloor()
{
	int nextfloor,up=0,down=0,i;//up������¥����������downͬ�� 
	for(i=0;i<3;i++)
	{
		if(inqueue.floor[i]!=0&&i>currentfloor)
	    {
			up++;
		}
		else if(inqueue.floor[i]!=0&&i<currentfloor)
		{
			down++;
		}
		if(outqueue.floor[i]!=0&&i>currentfloor)
	   	{
			up++;
		}
		else if(outqueue.floor[i]!=0&&i<currentfloor)
		{
			down++;
		}
    }
		if(up==0&&down==0)
		{
			indicator=0;
		}
		else if(up!=0&&down==0)
		{
			indicator=1;
		}
		else if(up==0&&down!=0)
		{
			indicator=-1;
		}
}
void Elevatorscheduling::going()
{
	if(indicator==1)
	{
	   	currentfloor++;
	}
	else if(indicator==-1)
	{
		currentfloor--;
	}
	t++;
}
int Elevatorscheduling::stop()
{
	int i,j,k=0,m;
   	for(i=0;i<3;i++)
	{
	   	if(currentfloor==i&&outqueue.floor[i]!=0)//��i���ǵ�ǰ¥�㣬������Ҫ��ȥ 
	   	{
	    	cout<<t<<' '<<currentfloor<<endl;
	    	m=i;
	    	people=people-outqueue.floor[i];
			outqueue.floor[i]=0;
			k=1;
		}
	}
	for(i=0;i<3;i++)
	{
	   	if(currentfloor==i&&inqueue.floor[i]!=0)//��i���ǵ�ǰ¥�㣬������Ҫ������ 
	   	{   
	   	    if(i!=m)
	   	    {
	   	    	cout<<t<<' '<<currentfloor<<endl;	
			}
	    	people=people+inqueue.floor[i];
	    	inqueue.floor[i]=0;
	    	for(j=0;j<3;j++)
	    	{
	    		if(waitqueue.floor[i][j]!=0)//������Ӧ�˵�i������󣬲�����i���Ŀ��¥��������� 
	    		{
	    			outqueue.floor[j]=outqueue.floor[j]+waitqueue.floor[i][j];
	    			waitqueue.floor[i][j]=0;
				}
			}
		k=1;
		}
	}
	if(k==1)
	{
		t++;
	}
	return k;
}
int Elevatorscheduling::allcomplete()
{
	int j,k=0;
	for(j=0;j<3;j++)//��������ﻹ������δ��ɣ�k=1 
	{
		if(inqueue.floor[j]!=0||outqueue.floor[j]!=0)
		{
			k=1;
		}
	}
	return k;
}
