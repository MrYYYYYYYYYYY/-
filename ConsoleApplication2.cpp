// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "head.h"
#include <iostream>
using namespace std;
//���struct�ṹ��
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
	//���������ֺ�����true��,false������������
	bool flag = true;
	//��ʼ������
	Map map;
	//��¼˫��������������Ա���
	Move result;
	//��ѭ������
////////////////////////////////////////////////////////////////
////����Ϊ��
/////////////////////////////////////////////////////////////////
	if (flag) {	
		//��ǰ���ӷ���trueΪ���� falseΪ����
		bool round = true;
		while (true) {
			if (round) {
				//��ȡ�����������
				result = map.strategy();
				//������Ϸ���ִ��
				if (map.avaliable(result)) {
					map.Red_move(result);
					//���浱ǰ����
					map.save();
					//�������
					map.print_map();
					//�������������Ϣ
					cout << "------------------------------------\n";
					//���ӷ�ת��
					round = !round;
				}
				//���岻�Ϸ���ֹͣ
				else {
					cout<<"�����Ƿ�����\n";
					// ����ֹͣ
					system("pause");
				}
				
			}
			else {
				//������������������
				int Pos[2];
				cin >> Pos[0] >> Pos[1];
				result.m_[0]= Pos[0];
				result.m_[1] = Pos[1];
				cin.ignore();
				//������Ϸ���ִ��
				if (map.avaliable(result)) {
					map.Blue_move(result);
					//���浱ǰ����
					map.save();
					//�������
					map.print_map();
					//���ӷ�ת��
					round = !round;
				}
				//���岻�Ϸ����������
				else {
					cout << "���ַǷ�����\n";
				}
				
			}
				
			//�������������ѭ��
			if (map.finished()) {
				break;
			}
		}
	}
////////////////////////////////////////////////////////////////////////////////
////����Ϊ��
//////////////////////////////////////////////////////////////////////////////
	else {		
		//��ǰ���ӷ���trueΪ���� falseΪ����
		bool round = false;
		while (true) {
			if (round) {
				//��ȡ�����������
				result = map.strategy();
				map.Blue_move(result);
				//������Ϸ���ִ��
				if (map.avaliable(result)) {
					map.Blue_move(result);
					//���浱ǰ����
					map.save();
					//�������
					map.print_map();
					//���ӷ�ת��
					round = !round;
				}
				//���岻�Ϸ���ֹͣ
				else {
					cout << "�����Ƿ�����\n";
					// ����ֹͣ
					system("pause");
				}

			}
			else {
				//������������������
				int Pos[2];
				cin >> Pos[0] >> Pos[1];
				result.m_[0] = Pos[0];
				result.m_[1] = Pos[1];
				//������Ϸ���ִ��
				if (map.avaliable(result)) {
					map.Red_move(result);
					//���浱ǰ����
					map.save();
					//�������
					map.print_map();
					//���ӷ�ת��
					round = !round;
				}
				//���岻�Ϸ����������
				else {
					cout << "���ַǷ�����\n";
				}

			}

			//�������������ѭ��
			if (map.finished()) {
				break;
			}
		}
	}
    return 0;
}

