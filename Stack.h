#ifndef STACK_H
#define STACK_H
#include"MazeNode.h"
//˳��ջ
const int DEFAULT_STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int);
	~SqStack();
	SqStack(const SqStack &src);
	SqStack operator=(const SqStack &src);
	//��ջ����
	void push( MazeNode &val);
	//��ջ����
	void pop();
	//��ȡջ��Ԫ��
	MazeNode top();
	//�ж�ջ��
	bool empty() const;
	//�ж�ջ��
	bool full() const;
	//��ʾջ�ϵ�����
	void showStack();
	//��ȡջ���������ж��ٸ�Ԫ��
	int getEleCount();
private:
	MazeNode *mpstack;
	int  mtop;
	int msize;
	void resizeStack();
};

#endif