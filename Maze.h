#include "MazeNode.h"
#include "Stack.h"

#ifndef Maze_H
#define Maze_H
//迷宫类
class Maze
{
public:
	Maze(int row, int col);
	~Maze();
	//方法一。解析用户输入的迷宫路径
	void analysisMazePath();
	//方法二。专门用来寻找迷宫路径的包装函数
	void searchMazePathPack();
	//实际用于找路劲的函数
	void searchMazePath();
	//方法三。用来进行打印迷宫路径的
	void printMazePath();
    //用于接收用户输入
	void input();
	//设置状态
	void status();
	//获取左边节点
	int getRightVal(int x,int y);
	int getDownVal(int x,int y);
	int getLeftVal(int x,int y);
	int getUpVal(int x,int y);
	

private:
	int _row;
	int _col;
	bool success;
	MazeNode **_pMaze;
	SqStack _stack;
};
#endif