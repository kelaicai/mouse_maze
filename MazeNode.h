#ifndef MazeNode_H
#define MazeNode_H
//��ʾÿһ���ڵ�λ�õ��ĸ�����
const int WAY_RIGHT = 0;
const int WAY_DOWN = 1;
const int WAY_LEFT = 2;
const int WAY_UP = 3;
const int WAY_SIZE = 4;

//ÿ�������״̬
const int WAY_YES = 0;
const int WAY_NO = 1;
const int WAY_ON = -1;

//�Թ�·���Ľڵ�����
class MazeNode
{
public:
	//Ĭ�Ϲ���
	MazeNode();
	//��ʼ������MazeNode
	int getMazeNodeVal();
	//�������캯��
	MazeNode(const MazeNode &src);
	//��ֵ����
	MazeNode& operator=(const MazeNode &src);
	//���ýڵ�����
	void setMazeNodeIndex(int x, int y);
	//���ýڵ�ֵ
	void setMazeNodeVal(int val);
	//���ýڵ������λ����Ϣ
	void setMazeNodeStatus(int dir,int status);
	//��ȡ�ڵ��dir����λ����Ϣ
	int getMazeNodeStatus(int dir);
	//�������������Ϣ
	void setLeft(int msg);
	//�������ҷ������Ϣ
	void setRight(int msg);
	//�������Ϸ������Ϣ
	void setUp(int msg);
	//�������·������Ϣ
	void setDown(int msg);
	//��ȡ�ڵ�����
	int getMazeNodeX();
	//��ȡ�ڵ�����Y
	int getMazeNodeY();
	//���ýڵ��ۺ���Ϣ
	void setMazeNode(int x,int y,int right,int down,int left,int up );
	void setMazeNodeX(int x);
	void setMazeNodeY(int y);
private:
	//��ʾ·����ֵ
	int _val;
	//��ʾ�ýڵ������λ��
	int _x;
	int _y;
	//�洢�ڵ��ĸ������״̬
	int _wayState[WAY_SIZE];
};
#endif

