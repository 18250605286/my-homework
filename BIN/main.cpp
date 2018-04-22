#include<iostream>
#include<fstream>
#include "elevator.h"
using namespace std;
int main()
{
	int n,i,j,time,nowfloor,destinationfloor,k=0,m=0;//time为请求时刻 
	Elevatorscheduling ele;
	freopen( "input.txt", "r", stdin);
	freopen( "output.txt", "w",stdout);
	cin>>n;
	for(i=0;;)
	{
		k=0;//用于判断是否退出循环 
		if(m==0&&i<n)//m=1说明上一请求未被处理，暂不输入下一请求（如果有的话） 
		{
			cin>>time>>nowfloor>>destinationfloor;
			m=1;	
		}
		if(ele.t>=time&&m==1)//如果时间到了请求发出的时刻，处理请求。m=1说明请求未被处理过 
		{
			ele.inqueue.floor[nowfloor]++;//使队列内第nowfloor层的请求数加一 
			ele.waitqueue.floor[nowfloor][destinationfloor]++;//同理，待到进电梯的请求执行后再将等候队列的请求置入待执行队列 
			i++;
			m=0;
		}
		ele.gotofloor();//判断运行方向 
		if(ele.stop()!=1)//如果电梯有停靠，那么电梯先不运行，执行下一循环，判断在新的时刻是否有请求 
		{
			ele.going();
		}
		k=ele.allcomplete();
		if(k==0&&i>=n)//当队列里请求都完成且没有新的请求 
		{
			break;
		}
	}
	return 0;
}
