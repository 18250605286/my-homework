#include<iostream>
#include<fstream>
#include "elevator.h"
using namespace std;
int main()
{
	freopen( "input.txt", "r", stdin);
	int n,i,j,time,nowfloor,destinationfloor;//time为请求时刻 
	int k0=0,k1=0,k2=0,m=0;
	Elevatorscheduling ele1,ele2,ele3;
	ele1.n=1;
	ele2.n=2;
	ele3.n=3;
	cin>>n;
	for(i=0;;)
	{
		k0=0;
		k1=0;
		k2=0;//用于判断是否退出循环 
		if(m==0&&i<n)//m!=0说明上一请求未被处理，暂不输入下一请求（如果有的话） 
		{
			cin>>time>>nowfloor>>destinationfloor;
			if(nowfloor%2!=0&&destinationfloor%2!=0)
			{
				if(ele1.num>ele2.num)
				{
					m=2;
				}
				else
				{
					m=1;
				}
			}
			else if((nowfloor%2==0||nowfloor==1)&&(destinationfloor%2==0||destinationfloor)==1)
			{
				if(ele3.num>ele2.num)
				{
					m=2;
				}
				else
				{
					m=3;
				}
			}
			else
			{
				m=2;
			}	
		}
		if(ele1.t>=time&&m==1)//如果时间到了请求发出的时刻，处理请求。m=1说明请求未被处理过 
		{
			ele1.inqueue.floor[nowfloor]++;//使队列内第nowfloor层的请求数加一 
			ele1.waitqueue.floor[nowfloor][destinationfloor]++;//同理，待到进电梯的请求执行后再将等候队列的请求置入待执行队列 
			ele1.num++;
			m=0;
			i++;
			continue;
		}
		else if(ele2.t>=time&&m==2)
		{
			ele2.inqueue.floor[nowfloor]++;//使队列内第nowfloor层的请求数加一 
			ele2.waitqueue.floor[nowfloor][destinationfloor]++;//同理，待到进电梯的请求执行后再将等候队列的请求置入待执行队列 
			ele2.num++;
			m=0;
			i++;
			continue;
		}
		else if(ele3.t>=time&&m==3)
		{
			ele3.inqueue.floor[nowfloor]++;//使队列内第nowfloor层的请求数加一 
			ele3.waitqueue.floor[nowfloor][destinationfloor]++;//同理，待到进电梯的请求执行后再将等候队列的请求置入待执行队列 
			ele3.num++;
			m=0;
			i++;
			continue;
		}
		ele1.gotofloor();//判断运行方向 
		ele2.gotofloor();
		ele3.gotofloor();
		if(ele1.stop()!=1)//如果电梯有停靠，那么电梯先不运行，执行下一循环，判断在新的时刻是否有请求 
		{
			ele1.going();
		}	
		if(ele2.stop()!=1)
		{
			ele2.going();
		}
		if(ele3.stop()!=1)
		{
			ele3.going();
		}
		k0=ele1.allcomplete();
		k1=ele2.allcomplete();
		k2=ele3.allcomplete();
		if(k0==0&&k1==0&&k2==0&&i>=n)//当队列里请求都完成且没有新的请求 
		{
			break;
		}
	}
	return 0;
}
