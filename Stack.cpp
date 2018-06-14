#include "Stack.h"
#include<iostream>
using namespace std;
/*    member vars
MazeNode *mpstack;
int mtop;
int msize;

*/
//默认带参数的构造函数
SqStack::SqStack(int size = 10)
{
	msize = size;
	mtop = -1;
	mpstack = new MazeNode[msize];
}
//析构函数
SqStack::~SqStack()
{
	delete[] mpstack;
	mtop = -1;
	msize = 0;
}
//拷贝构造函数
SqStack::SqStack(const SqStack &src)
{
	msize = src.msize;
	delete[] mpstack;
	MazeNode* tmp = new MazeNode[msize];
	mpstack = tmp;
	for (int i = 0; i < msize; i++)
	{
		mpstack[i] = src.mpstack[i];
	}
}

SqStack SqStack::operator=(const SqStack &src)
{
	if (this == &src) //自赋值
	{
		return *this;
	}
	//src的msize可能比this对象的msize大，也可能小
	msize = src.msize;
	delete[] mpstack;
	MazeNode *ptr = new MazeNode[msize];
	mpstack = ptr;
	ptr = NULL;
	for (int i = 0; i < msize; i++)
	{
		mpstack[i] = src.mpstack[i];
	}
	return *this;
}
//入栈操作
void SqStack::push( MazeNode &val)
{
	if (full())
	{
		cout << "stack is full" << endl;
		//resizeStack():
		return;
	}
	mpstack[mtop++] = val;
	/*
	mpstack[mtop].setMazeNodeVal(val.getMazeNodeVal());
	mpstack[mtop].setRight(val.getMazeNodeStatus(0));
	mpstack[mtop].setDown(val.getMazeNodeStatus(1));
	mpstack[mtop].setLeft(val.getMazeNodeStatus(2));
	mpstack[mtop].setUp(val.getMazeNodeStatus(3));
	mpstack[mtop].setMazeNodeX(val.getMazeNodeX());
	mpstack[mtop].setMazeNodeY(val.getMazeNodeY());
	mtop++;
	*/
}
//出栈操作
void SqStack::pop()
{
	if (empty())
	{
		cout << "栈已经空" << endl;
		return;
	}
	mtop--;
}
//获取栈顶元素
MazeNode SqStack::top()
{
	if (empty())
	{
		//栈空
		cout << "空栈" << endl;
		return MazeNode();
	}
	return mpstack[mtop-1];
}

//判断栈空
bool SqStack::empty()  const
{
	return mtop == -1;
}
//判断栈满
bool SqStack::full()  const
{
	return mtop == msize - 1;
}

void SqStack::showStack()
{
	cout << "当前顺序栈中的数据  栈基---》栈顶" << endl;
	if (empty())
	{
		cout << "当前栈为空" << endl;
		return;
	}

	for (int i = 0; i <= mtop; i++)
	{
		cout << mpstack[i].getMazeNodeVal()<< " ";
	}
	cout << endl;

}
/**/
void SqStack::resizeStack()
{
	int size = msize * 2;
	MazeNode *tmp = new MazeNode[size];
	for (int i = 0; i < size / 2; i++)
	{
		tmp[i] = mpstack[i];
	}
	delete[] mpstack;
	mpstack = tmp;
	msize = size;
}

int SqStack::getEleCount()
{
	if (empty())
	{
		return -1;
	}
	return mtop - 1;
}