#ifndef STACK_H
#define STACK_H
#include"MazeNode.h"
//顺序栈
const int DEFAULT_STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int);
	~SqStack();
	SqStack(const SqStack &src);
	SqStack operator=(const SqStack &src);
	//入栈操作
	void push( MazeNode &val);
	//出栈操作
	void pop();
	//获取栈顶元素
	MazeNode top();
	//判断栈空
	bool empty() const;
	//判断栈满
	bool full() const;
	//显示栈上的数据
	void showStack();
	//获取栈现在里面有多少个元素
	int getEleCount();
private:
	MazeNode *mpstack;
	int  mtop;
	int msize;
	void resizeStack();
};

#endif