#include<iostream>
#include<fstream>
#include "elevator.h"
using namespace std;
int main()
{
	freopen( "input.txt", "r", stdin);
	int n,i,j,time,nowfloor,destinationfloor;//timeΪ����ʱ�� 
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
		k2=0;//�����ж��Ƿ��˳�ѭ�� 
		if(m==0&&i<n)//m!=0˵����һ����δ�������ݲ�������һ��������еĻ��� 
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
		if(ele1.t>=time&&m==1)//���ʱ�䵽�����󷢳���ʱ�̣���������m=1˵������δ������� 
		{
			ele1.inqueue.floor[nowfloor]++;//ʹ�����ڵ�nowfloor�����������һ 
			ele1.waitqueue.floor[nowfloor][destinationfloor]++;//ͬ�����������ݵ�����ִ�к��ٽ��Ⱥ���е����������ִ�ж��� 
			ele1.num++;
			m=0;
			i++;
			continue;
		}
		else if(ele2.t>=time&&m==2)
		{
			ele2.inqueue.floor[nowfloor]++;//ʹ�����ڵ�nowfloor�����������һ 
			ele2.waitqueue.floor[nowfloor][destinationfloor]++;//ͬ�����������ݵ�����ִ�к��ٽ��Ⱥ���е����������ִ�ж��� 
			ele2.num++;
			m=0;
			i++;
			continue;
		}
		else if(ele3.t>=time&&m==3)
		{
			ele3.inqueue.floor[nowfloor]++;//ʹ�����ڵ�nowfloor�����������һ 
			ele3.waitqueue.floor[nowfloor][destinationfloor]++;//ͬ�����������ݵ�����ִ�к��ٽ��Ⱥ���е����������ִ�ж��� 
			ele3.num++;
			m=0;
			i++;
			continue;
		}
		ele1.gotofloor();//�ж����з��� 
		ele2.gotofloor();
		ele3.gotofloor();
		if(ele1.stop()!=1)//���������ͣ������ô�����Ȳ����У�ִ����һѭ�����ж����µ�ʱ���Ƿ������� 
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
		if(k0==0&&k1==0&&k2==0&&i>=n)//�����������������û���µ����� 
		{
			break;
		}
	}
	return 0;
}
