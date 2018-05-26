#include<iostream>
using namespace std;
class queue//用于储存请求，毎有一个去往x楼层的请求，就使floor【x】加一 
{
	public:
		int n;
		int floor[11];
		queue();
};
class wait//用于储存在x层请求要去往的楼层，如在x层的人要去y层，则使floor【x】【y】加一 
{
	public:
		int floor[11][11];
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
	    int num;//电梯外等待的人数及电梯内人数 
	    int t;//时间 
	    int n;//判断输出到哪个文件 
	    Elevatorscheduling();//初始化 
	    void gotofloor(); //判断运行方向 
		void going();//电梯运行 
        int stop(); //停靠在当前楼层
        int stop(char *argv[]);
	    int allcomplete();//判断请求是否全部完成 
};
