#include<iostream>
#include"Maze.h"
#include"MazeNode.h"
using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	cout << "������������" << endl;
	cin >> x >> y;
	if (x < 0 || y < 0)
	{
		exit(0);
	}
	Maze mm(x, y);
	mm.analysisMazePath();
	mm.searchMazePathPack();
	mm.printMazePath();
	system("pause");
	cout << "����" << endl;
	return 0;
}