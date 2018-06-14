#include "MazeNode.h"
#include "Stack.h"

#ifndef Maze_H
#define Maze_H
//�Թ���
class Maze
{
public:
	Maze(int row, int col);
	~Maze();
	//����һ�������û�������Թ�·��
	void analysisMazePath();
	//��������ר������Ѱ���Թ�·���İ�װ����
	void searchMazePathPack();
	//ʵ��������·���ĺ���
	void searchMazePath();
	//���������������д�ӡ�Թ�·����
	void printMazePath();
    //���ڽ����û�����
	void input();
	//����״̬
	void status();
	//��ȡ��߽ڵ�
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