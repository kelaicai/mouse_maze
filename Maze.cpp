#include"Maze.h"
#include"MazeNode.h"
#include<iostream>
using namespace std;
Maze::Maze(int row, int col) :_stack(row*col), _row(row), _col(col), success(false)
{
	 _pMaze = new  MazeNode*[row];
	 for (int i = 0; i < row; i++)
	 {
			 _pMaze[i] = new MazeNode[col];
	 }
	 for (int i = 0; i < row; i++)
	 {
		 for (int j = 0; j < col; j++)
		 {
			 _pMaze[i][j].setMazeNodeIndex(i, j);
		 }
	 }
}

void Maze::input()
{
	int **tmp = new int*[_row];
	for (int i = 0; i < _row; i++)
	{
		tmp[i] = new int[_col];
	}

	cout << "�����������Թ�����" << endl;


	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cin >> tmp[i][j];
		}
	}
	cout << "�Թ��������" << endl;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{

			_pMaze[i][j].setMazeNodeVal(tmp[i][j]);
		}	
	}


	//�ͷ�tmp�ڴ�
	for (int i = 0; i < _row; i++)
	{
		delete[] tmp[i];
	}
	delete tmp;
}


void Maze::analysisMazePath()
{
	input();

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			for (int k = 0; k < WAY_SIZE; k++)
			{
				int rVal = getRightVal(i, j);
				int dVal = getDownVal(i,j);
				int lVal = getLeftVal(i,j);
				int uVal = getUpVal(i,j);
				_pMaze[i][j].setMazeNode(i, j, rVal, dVal, lVal, uVal);
			}
		}
	}
	
}

void Maze::printMazePath()
{

	if (success==false)
	{
		cout << "û���ҵ�·��" << endl;
		return;
	}

	
	MazeNode tmp;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			tmp = _stack.top();
			int x = tmp.getMazeNodeX();
			int y = tmp.getMazeNodeY();
			_pMaze[x][y].setMazeNodeVal(WAY_ON);
			_stack.pop();
		}
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << _pMaze[i][j].getMazeNodeVal() << "  ";
		}
		cout << endl;
	}
}
Maze::~Maze()
{
	for (int i = 0; i < _row; i++)
	{
		delete[] _pMaze[i];
	}
	delete _pMaze;
	_row = 0;
	_col = 0;
}


void Maze::searchMazePathPack()
{
	if (_pMaze[0][0].getMazeNodeVal() == WAY_NO)
	{
		cout << "��������һ����������Թ�" << endl;
		success = false;
		return;
	}

	_stack.push(_pMaze[0][0]);

	while (!_stack.empty())
	{
		MazeNode tmpNode = _stack.top();
		/*


		for (int i = 0; i < WAY_SIZE; i++)
		{
		cout << _stack.top().getMazeNodeStatus(i) << "  ";
		}*/
		cout << endl;
		if (tmpNode.getMazeNodeX() == _row - 1 && tmpNode.getMazeNodeY() == _col - 1)
		{
			success = true;
			break;
		}
		int x = tmpNode.getMazeNodeX();
		int y = tmpNode.getMazeNodeY();
		int tr = tmpNode.getMazeNodeStatus(0);
		int td = tmpNode.getMazeNodeStatus(1);
		int tl = tmpNode.getMazeNodeStatus(2);
		int tu = tmpNode.getMazeNodeStatus(3);
		if (tr == WAY_YES)
		{

			/*   ��ǰ�ڵ���ұ�������У��ȵ�ǰ�ڵ�÷�������ΪWAY_NO
				��������һ���ڵ�����÷����״̬����ΪWAY_NO
				*/

			tmpNode.setRight(WAY_NO);
			_pMaze[x][y + 1].setLeft(WAY_NO);
			_stack.push(_pMaze[x][y + 1]);
			tmpNode = _pMaze[x][y + 1];
			continue;  //ֱ�ӽ�����һ���ڵ�
		}
		else if (td == WAY_YES)
		{
			tmpNode.setDown(WAY_NO);
			_pMaze[x + 1][y].setUp(WAY_NO);
			_stack.push(_pMaze[x + 1][y]);
			tmpNode = _pMaze[x + 1][y];
			continue;

		}
		else if (tl = WAY_YES)
		{
			tmpNode.setLeft(WAY_NO);
			_pMaze[x][y - 1].setRight(WAY_NO);
			_stack.push(_pMaze[x][y - 1]);
			tmpNode = _pMaze[x][y - 1];
			continue;
		}
		else if (tu == WAY_YES)
		{
			tmpNode.setDown(WAY_NO);
			_pMaze[x - 1][y].setUp(WAY_NO);
			_stack.push(_pMaze[x + 1][y]);
			tmpNode = _pMaze[x + 1][y];
			continue;
		}
		if (_stack.empty())
		{
			success = true;
			cout << "û��·"<<endl;
			return;
		}
		_stack.pop();
		tmpNode = _stack.top();
	}
}

int Maze::getRightVal(int x,int y)
{
	if (y + 1 >= _col)
	{
		return 1;
	}
		return _pMaze[x][y + 1].getMazeNodeVal();

}

int Maze::getDownVal(int x,int y)
{
	if (x + 1 >= _row)
	{
		return 1;
	}
	return _pMaze[x + 1][y].getMazeNodeVal();

}
int Maze::getLeftVal(int x,int y)
{
	if (y - 1 < 0)
	{
		return 1;
	}
	return _pMaze[x][y - 1].getMazeNodeVal();
}

int Maze::getUpVal(int x,int y)
{
	if (x - 1 < 0)
	{
		return 1;
	}
	return _pMaze[x - 1][y].getMazeNodeVal();
}
