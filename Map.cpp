#include "stdafx.h"
#include "head.h"
#include <iostream>
Map::Map()
{
	//初始化棋面
	for (int i = 0; i <row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Map_.a[i][j] = 0;
		};

	};
	//步数为初始化0
	this->index = 0;
};
Map::~Map(){}
bool Map::Blue_move(Move result) {
	bool flag;
	if (this->Map_.a[result.m_[0]][result.m_[1]] == 0) {
		this->Map_.a[result.m_[0]][result.m_[1]] = 2;
		flag = true;
	}
	else
		flag = false;
	return flag;
}
bool Map::Red_move(Move result) {
	bool flag;
	if (this->Map_.a[result.m_[0]][result.m_[1]] == 0) {
		this->Map_.a[result.m_[0]][result.m_[1]] = 1;
		flag = true;
	}
	else
		flag = false;
	return flag;
}
element Map::Get_map() {
	return Map_;
}
Move Map::strategy() {
	Move move;
	return move;
}
bool Map::finished() {
	return false;
}
bool Map::avaliable(Move move) {
	bool flag=false;
	//在棋盘范围内
	if (move.m_[0] < 11 && move.m_[0] >= 0 && move.m_[1] < 11 && move.m_[1] >= 0) {
		if (this->Map_.a[move.m_[0]][move.m_[1]] == 0) {
			//若当前位置未落子
			flag = true;
		}
	}
	return flag;
}
void Map::save(){
	this->Stack.push(Map_);
}
void Map::print_map() {
	for (int i = 0; i < 40; i++) {
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < 11; i++) {
		//开头空格
		for (int k = 0; k < i; k++) {
			cout << " ";
		}
		for (int j = 0; j < 11; j++) {
			if (this->Map_.a[i][j] == 0) {
				cout << "- ";
			}
			else if (this->Map_.a[i][j] == 1) {
				cout << "# ";
			}
			else if (this->Map_.a[i][j] == 2) {
				cout << "* ";
			}
		}
		cout << "\n";
	}
}
