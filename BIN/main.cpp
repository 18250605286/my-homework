#include<iostream>
#include<fstream>
#include "elevator.h"
using namespace std;
int main()
{
	int n,i,j,time,nowfloor,destinationfloor,k=0,m=0;//timeΪ����ʱ�� 
	Elevatorscheduling ele;
	freopen( "input.txt", "r", stdin);
	freopen( "output.txt", "w",stdout);
	cin>>n;
	for(i=0;;)
	{
		k=0;//�����ж��Ƿ��˳�ѭ�� 
		if(m==0&&i<n)//m=1˵����һ����δ�������ݲ�������һ��������еĻ��� 
		{
			cin>>time>>nowfloor>>destinationfloor;
			m=1;	
		}
		if(ele.t>=time&&m==1)//���ʱ�䵽�����󷢳���ʱ�̣���������m=1˵������δ������� 
		{
			ele.inqueue.floor[nowfloor]++;//ʹ�����ڵ�nowfloor�����������һ 
			ele.waitqueue.floor[nowfloor][destinationfloor]++;//ͬ�����������ݵ�����ִ�к��ٽ��Ⱥ���е����������ִ�ж��� 
			i++;
			m=0;
		}
		ele.gotofloor();//�ж����з��� 
		if(ele.stop()!=1)//���������ͣ������ô�����Ȳ����У�ִ����һѭ�����ж����µ�ʱ���Ƿ������� 
		{
			ele.going();
		}
		k=ele.allcomplete();
		if(k==0&&i>=n)//�����������������û���µ����� 
		{
			break;
		}
	}
	return 0;
}
