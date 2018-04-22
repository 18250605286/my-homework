#include<iostream>
using namespace std;
class queue//用于储存请求，毎有一个去往x楼层的请求，就使floor【x】加一 
{
	public:
		int n;
		int floor[3];
		queue();
};
class wait//用于储存在x层请求要去往的楼层，如在x层的人要去y层，则使floor【x】【y】加一 
{
	public:
		int floor[3][3];
		wait();
};
class Elevatorscheduling
{
	public:
		queue inqueue,outqueue;//inqueue要进电梯的队列，outqueue要出电梯的队列 
		wait waitqueue;//还未进电梯的目的地队列 
	    int currentfloor; //当前位置
	    int indicator; //运行方向
	    int people;//电梯内人数 
	    int t;//时间 
	    Elevatorscheduling();//初始化 
	    void gotofloor(); //判断运行方向 
		void going();//电梯运行 
        int stop(); //停靠在当前楼层
	    int allcomplete();
};
