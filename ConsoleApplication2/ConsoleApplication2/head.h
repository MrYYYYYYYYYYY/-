#pragma once
#include <stack>
using namespace std;
//���巺����ջ�ṹ
struct element {
	int a[11][11];
};
struct Move {
	int m_[2] = {0,0};
};
class Map
{
private:
	//��¼��ǰ����
	static int index ;
	//������������
	static const int row = 11;
	//������������
	static const int col = 11;
	//���屣�沽��
	int saved_steps = 50;
	//������������
	element Map_;
	//��������洢ջ
	stack<element> Stack;
public:
	Map();
	//��������2
	bool Blue_move(Move result);
	//�췽����1
	bool Red_move(Move result);
	//��ȡ��ǰ������Ϣ
	element Get_map();
	//��ȡ��ǰ�������,������д�����㷨�����ΪMove��������
	Move strategy();
	//�ж��Ƿ�������
	bool finished();
	//�жϵ�ǰ���ܷ�����
	bool avaliable(Move move);
	//���浱ǰ����������洢ջ
	void save();
	//�����ǰ���
	void print_map();
	//��
	~Map();
};



