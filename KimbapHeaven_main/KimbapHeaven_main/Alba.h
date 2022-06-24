#pragma once
#include <string>
#include <iostream>
#include "kitchen.h"
using namespace std;
#define STATE 3
#define MENU_NUM 10

// �˹�
// �Ӽ� : ����, �ϰ� �ִ� ��, ���� �� ��
// �ൿ : �ֹ� ����, ���̺� û��
class Alba
{
protected:
public:
	int _state; // 0 : �ֹ� ����, 1 : ���̺� û�� ��, 2 : ��� ��
	string* _nowAction;
	string* _nextAction;

	Alba()
		: _state(0)
	{	// �տ� �� �� ���̺� ��ȣ ���̱�
		_nowAction = new string[STATE] { "�ֹ� ����", "���̺� û�� ��", "��� ��" };
		_nextAction = new string[STATE] { "�ֹ� ����", "���̺� û�� ��", "��� ��" };
	}
	Alba(const Alba& copyAlba) // ���� �����ڸ� ����غ���~ (���� ����)
		: _state(0)
	{
		_nowAction = new string[STATE];
		_nextAction = new string[STATE];
	}

	~Alba()
	{
		delete[] _nowAction;
		delete[] _nextAction;
	}

	int Order(Kitchen *menu);			// �޴� �ֹ�
	void TableCleen();						// ���̺� û��

};

