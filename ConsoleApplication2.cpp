// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"
#include <iostream>
using namespace std;
//输出struct结构体
void print_array(element Map){
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cout << Map.a[i][j];
			}
			cout << "\n";
		}
	}
int main()
{
	//决定己方持何种棋true红,false蓝，红先蓝后
	bool flag = true;
	//初始化棋盘
	Map map;
	//记录双方方单步行棋策略变量
	Move result;
	//主循环函数
////////////////////////////////////////////////////////////////
////己方为红
/////////////////////////////////////////////////////////////////
	if (flag) {	
		//当前持子方，true为己方 false为对手
		bool round = true;
		while (true) {
			if (round) {
				//获取己方行棋策略
				result = map.strategy();
				//若行棋合法则执行
				if (map.avaliable(result)) {
					map.Red_move(result);
					//保存当前棋盘
					map.save();
					//输出棋面
					map.print_map();
					//输出己方行棋信息
					cout << "------------------------------------\n";
					//持子方转换
					round = !round;
				}
				//行棋不合法则停止
				else {
					cout<<"己方非法落子\n";
					// 程序停止
					system("pause");
				}
				
			}
			else {
				//键盘输入对手行棋策略
				int Pos[2];
				cin >> Pos[0] >> Pos[1];
				result.m_[0]= Pos[0];
				result.m_[1] = Pos[1];
				cin.ignore();
				//若行棋合法则执行
				if (map.avaliable(result)) {
					map.Blue_move(result);
					//保存当前棋盘
					map.save();
					//输出棋面
					map.print_map();
					//持子方转换
					round = !round;
				}
				//行棋不合法则继续输入
				else {
					cout << "对手非法落子\n";
				}
				
			}
				
			//如果结束则跳出循环
			if (map.finished()) {
				break;
			}
		}
	}
////////////////////////////////////////////////////////////////////////////////
////己方为蓝
//////////////////////////////////////////////////////////////////////////////
	else {		
		//当前持子方，true为己方 false为对手
		bool round = false;
		while (true) {
			if (round) {
				//获取己方行棋策略
				result = map.strategy();
				map.Blue_move(result);
				//若行棋合法则执行
				if (map.avaliable(result)) {
					map.Blue_move(result);
					//保存当前棋盘
					map.save();
					//输出棋面
					map.print_map();
					//持子方转换
					round = !round;
				}
				//行棋不合法则停止
				else {
					cout << "己方非法落子\n";
					// 程序停止
					system("pause");
				}

			}
			else {
				//键盘输入对手行棋策略
				int Pos[2];
				cin >> Pos[0] >> Pos[1];
				result.m_[0] = Pos[0];
				result.m_[1] = Pos[1];
				//若行棋合法则执行
				if (map.avaliable(result)) {
					map.Red_move(result);
					//保存当前棋盘
					map.save();
					//输出棋面
					map.print_map();
					//持子方转换
					round = !round;
				}
				//行棋不合法则继续输入
				else {
					cout << "对手非法落子\n";
				}

			}

			//如果结束则跳出循环
			if (map.finished()) {
				break;
			}
		}
	}
    return 0;
}

