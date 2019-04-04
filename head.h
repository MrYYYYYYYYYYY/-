#pragma once
#include <stack>
using namespace std;
//定义泛型类栈结构
struct element {
	int a[11][11];
};
struct Move {
	int m_[2] = {0,0};
};
class Map
{
private:
	//记录当前步数
	static int index ;
	//定义棋面行数
	static const int row = 11;
	//定义棋面列数
	static const int col = 11;
	//定义保存步数
	int saved_steps = 50;
	//定义棋面数组
	element Map_;
	//定义棋面存储栈
	stack<element> Stack;
public:
	Map();
	//蓝方走棋2
	bool Blue_move(Move result);
	//红方走棋1
	bool Red_move(Move result);
	//获取当前棋面信息
	element Get_map();
	//获取当前行棋策略,其中填写搜索算法，输出为Move类型坐标
	Move strategy();
	//判定是否结束棋局
	bool finished();
	//判断当前点能否行棋
	bool avaliable(Move move);
	//保存当前棋面至棋面存储栈
	void save();
	//输出当前棋局
	void print_map();
	//将
	~Map();
};



