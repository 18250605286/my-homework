#include<iostream>
using namespace std;
class queue//���ڴ������󣬚���һ��ȥ��x¥������󣬾�ʹfloor��x����һ 
{
	public:
		int n;
		int floor[11];
		queue();
};
class wait//���ڴ�����x������Ҫȥ����¥�㣬����x�����Ҫȥy�㣬��ʹfloor��x����y����һ 
{
	public:
		int floor[11][11];
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
	    int num;//������ȴ������������������� 
	    int t;//ʱ�� 
	    int n;//�ж�������ĸ��ļ� 
	    Elevatorscheduling();//��ʼ�� 
	    void gotofloor(); //�ж����з��� 
		void going();//�������� 
        int stop(); //ͣ���ڵ�ǰ¥��
        int stop(char *argv[]);
	    int allcomplete();//�ж������Ƿ�ȫ����� 
};
