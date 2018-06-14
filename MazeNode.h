#ifndef MazeNode_H
#define MazeNode_H
//表示每一个节点位置的四个方向
const int WAY_RIGHT = 0;
const int WAY_DOWN = 1;
const int WAY_LEFT = 2;
const int WAY_UP = 3;
const int WAY_SIZE = 4;

//每个方向的状态
const int WAY_YES = 0;
const int WAY_NO = 1;
const int WAY_ON = -1;

//迷宫路径的节点类型
class MazeNode
{
public:
	//默认构造
	MazeNode();
	//初始化行内MazeNode
	int getMazeNodeVal();
	//拷贝构造函数
	MazeNode(const MazeNode &src);
	//赋值重载
	MazeNode& operator=(const MazeNode &src);
	//设置节点坐标
	void setMazeNodeIndex(int x, int y);
	//设置节点值
	void setMazeNodeVal(int val);
	//设置节点各个方位的信息
	void setMazeNodeStatus(int dir,int status);
	//获取节点第dir个方位的信息
	int getMazeNodeStatus(int dir);
	//设置向左方向的信息
	void setLeft(int msg);
	//设置向右方向的信息
	void setRight(int msg);
	//设置向上方向的信息
	void setUp(int msg);
	//设置向下方向的信息
	void setDown(int msg);
	//获取节点坐标
	int getMazeNodeX();
	//获取节点坐标Y
	int getMazeNodeY();
	//设置节点综合信息
	void setMazeNode(int x,int y,int right,int down,int left,int up );
	void setMazeNodeX(int x);
	void setMazeNodeY(int y);
private:
	//表示路径的值
	int _val;
	//表示该节点的坐标位置
	int _x;
	int _y;
	//存储节点四个方向的状态
	int _wayState[WAY_SIZE];
};
#endif

