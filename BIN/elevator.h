#include<iostream>
using namespace std;
class queue//���ڴ������󣬚���һ��ȥ��x¥������󣬾�ʹfloor��x����һ 
{
	public:
		int n;
		int floor[3];
		queue();
};
class wait//���ڴ�����x������Ҫȥ����¥�㣬����x�����Ҫȥy�㣬��ʹfloor��x����y����һ 
{
	public:
		int floor[3][3];
		wait();
};
class Elevatorscheduling
{
	public:
		queue inqueue,outqueue;//inqueueҪ�����ݵĶ��У�outqueueҪ�����ݵĶ��� 
		wait waitqueue;//��δ�����ݵ�Ŀ�ĵض��� 
	    int currentfloor; //��ǰλ��
	    int indicator; //���з���
	    int people;//���������� 
	    int t;//ʱ�� 
	    Elevatorscheduling();//��ʼ�� 
	    void gotofloor(); //�ж����з��� 
		void going();//�������� 
        int stop(); //ͣ���ڵ�ǰ¥��
	    int allcomplete();
};
