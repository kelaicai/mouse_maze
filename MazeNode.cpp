#include"MazeNode.h"

MazeNode::MazeNode()
{
	_val = 0;
	_x = 0;
	_y = 0;
for (int i = 0; i < WAY_SIZE; i++)
	{
		_wayState[i] = 0;  //初始化四个方向为可行
	}
}
//初始化迷宫节点的坐标
void MazeNode::setMazeNodeIndex(int x, int y)
{
	_x = x;
	_y = y;
}

int MazeNode::getMazeNodeVal()
{
	return _val;
}

void MazeNode::setMazeNodeVal(int val)
{
	_val = val;
}

void MazeNode::setMazeNodeStatus(int dir,int status)
{
	_wayState[dir] = status;
}

int MazeNode::getMazeNodeStatus(int dir)
{
	return _wayState[dir];
}

MazeNode::MazeNode(const MazeNode &src)
{
	
	_val = src._val;
	_x = src._x;
	_y = src._y;
	for (int i = 0; i < WAY_SIZE; i++)
	{
		_wayState[i] = src._wayState[i];
	}
}

MazeNode& MazeNode::operator=(const MazeNode &src)
{
	if (this == &src)
	{
		return *this;
	}
	_val = src._val;
	_x = src._x;
	_y = src._y;
	for (int i = 0; i < WAY_SIZE; i++)
	{
		_wayState[i] = src._wayState[i];
	}
	return *this;
}

int MazeNode::getMazeNodeX()
{
	return _x;
}

int MazeNode::getMazeNodeY()
{
	return _y;
}


void MazeNode::setMazeNode(int x, int y, int right, int down, int left, int up)
{
	_x = x;
	_y = y;
	_wayState[WAY_RIGHT] = right;
	_wayState[WAY_DOWN] = down;
	_wayState[WAY_LEFT] = left;
	_wayState[WAY_UP] = up;
}

void MazeNode::setLeft(const int msg)
{
	_wayState[2] = msg;
}

void MazeNode::setRight(const int msg)
{
	_wayState[0] = msg;
}

void MazeNode::setUp(const int msg)
{
	_wayState[3] = msg;
}

void MazeNode::setDown(const int msg)
{
	_wayState[1] = msg;
}

void MazeNode::setMazeNodeX(int x)
{
	_x = x;
}
void MazeNode::setMazeNodeY(int y)
{
	_y = y;
}