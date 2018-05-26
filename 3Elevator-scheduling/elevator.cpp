#include<iostream>
#include<fstream>
#include "elevator.h"
queue::queue()
{
	int i;
	for(i=1;i<11;i++)
	{
		floor[i]=0;
	}
	n=0;
}
wait::wait()
{
	int i,j;
	for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
		{
			floor[i][j]=0;
		}
	}
}
Elevatorscheduling::Elevatorscheduling()
{
	currentfloor=1;
	indicator=0;
	people=0;
	num=0; 
	t=0;
}
void Elevatorscheduling::gotofloor()
{
	int nextfloor,up=0,down=0,i;//up往更高楼层请求数，down同理 
	for(i=1;i<11;i++)
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
	else if(indicator==0&&up!=0&&down!=0)
	{
		indicator=1;
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
	if(n==1) 
	{
		freopen("output1.txt", "a", stdout);
	}
	else if(n==2)
	{
		freopen("output2.txt", "a", stdout);
	}
	else if(n==3)
	{
		freopen("output3.txt", "a", stdout);
	}
   	for(i=1;i<11;i++)
	{
	   	if(currentfloor==i&&outqueue.floor[i]!=0)//第i层是当前楼层，且有人要出去 
	   	{
	    	cout<<t<<' '<<currentfloor<<endl;
	    	m=i;
	    	people=people-outqueue.floor[i];
	    	num=num-outqueue.floor[i];
		    outqueue.floor[i]=0;
			k=1;
		}
	}
	for(i=1;i<11;i++)
	{
		if(currentfloor==i&&inqueue.floor[i]!=0)//第i层是当前楼层，且有人要进电梯 
	   	{   

	   	    if(i!=m)
	   	    {
	   	    	cout<<t<<' '<<currentfloor<<endl;	
		    }	
	    	people=people+inqueue.floor[i];
	    	inqueue.floor[i]=0;
	    
	    	for(j=1;j<11;j++)
	    	{
	    		if(waitqueue.floor[i][j]!=0)//电梯响应了第i层的请求，并将第i层的目标楼层置入队列 
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
	fclose(stdout);
	return k;
}
int Elevatorscheduling::stop(char *argv[])
{
	int i,j,k=0,m;
	if(n==1) 
	{
		freopen(argv[2], "a", stdout);
	}
	else if(n==2)
	{
		freopen(argv[3], "a", stdout);
	}
	else if(n==3)
	{
		freopen(argv[4], "a", stdout);
	}
   	for(i=1;i<11;i++)
	{
	   	if(currentfloor==i&&outqueue.floor[i]!=0)//第i层是当前楼层，且有人要出去 
	   	{
	    	cout<<t<<' '<<currentfloor<<endl;
	    	m=i;
	    	people=people-outqueue.floor[i];
	    	num=num-outqueue.floor[i];
		    outqueue.floor[i]=0;
			k=1;
		}
	}
	for(i=1;i<11;i++)
	{
		if(currentfloor==i&&inqueue.floor[i]!=0)//第i层是当前楼层，且有人要进电梯 
	   	{   

	   	    if(i!=m)
	   	    {
	   	    	cout<<t<<' '<<currentfloor<<endl;	
		    }	
	    	people=people+inqueue.floor[i];
	    	inqueue.floor[i]=0;
	    
	    	for(j=1;j<11;j++)
	    	{
	    		if(waitqueue.floor[i][j]!=0)//电梯响应了第i层的请求，并将第i层的目标楼层置入队列 
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
	fclose(stdout);
	return k;
}
int Elevatorscheduling::allcomplete()
{
	int j,k=0;//如果队列里还有请求未完成，k=1 
	if(num!=0||people!=0)
	{
		k=1;
	}
	return k;
}
