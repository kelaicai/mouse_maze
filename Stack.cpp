#include "Stack.h"
#include<iostream>
using namespace std;
/*    member vars
MazeNode *mpstack;
int mtop;
int msize;

*/
//Ĭ�ϴ������Ĺ��캯��
SqStack::SqStack(int size = 10)
{
	msize = size;
	mtop = -1;
	mpstack = new MazeNode[msize];
}
//��������
SqStack::~SqStack()
{
	delete[] mpstack;
	mtop = -1;
	msize = 0;
}
//�������캯��
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
	if (this == &src) //�Ը�ֵ
	{
		return *this;
	}
	//src��msize���ܱ�this�����msize��Ҳ����С
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
//��ջ����
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
//��ջ����
void SqStack::pop()
{
	if (empty())
	{
		cout << "ջ�Ѿ���" << endl;
		return;
	}
	mtop--;
}
//��ȡջ��Ԫ��
MazeNode SqStack::top()
{
	if (empty())
	{
		//ջ��
		cout << "��ջ" << endl;
		return MazeNode();
	}
	return mpstack[mtop-1];
}

//�ж�ջ��
bool SqStack::empty()  const
{
	return mtop == -1;
}
//�ж�ջ��
bool SqStack::full()  const
{
	return mtop == msize - 1;
}

void SqStack::showStack()
{
	cout << "��ǰ˳��ջ�е�����  ջ��---��ջ��" << endl;
	if (empty())
	{
		cout << "��ǰջΪ��" << endl;
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