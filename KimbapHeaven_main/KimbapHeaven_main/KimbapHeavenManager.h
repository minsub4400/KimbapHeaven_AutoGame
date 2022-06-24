#pragma once
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <string>
#include "kitchen.h"
#include "Alba.h"

#define MENUARR 10

class KimbapHeavenManager
{
public:
	bool	_openStore;			// �Ĵ� ���� ���� true - open, false - close
	int		_days;					// ��¥(��)
	int		_getMoney;			// ��(Month)�� �� ��
	int		_time;					// �ð�
	int		_visitor;				// �湮��
	int		_delayConsumer;   // �����
	int*	_consumer;			// ���̺� ������ �մ� ��
	int		_count;				// ���̺� ��
	bool* _tableUsed;			// ���̺� ��� ����
	KimbapHeavenManager(int visitorCount, int tableCount)
		: _openStore(false), _days(1), _getMoney(0), _visitor(visitorCount), _time(0), _delayConsumer(visitorCount), _count(tableCount)
	{
		_consumer = new int[tableCount] { 0 };
		_tableUsed = new bool[tableCount] { false };

		if (_openStore == false)
		{
			_openStore = true; // �Ĵ繮�� ����
		}
	}
	~KimbapHeavenManager()
	{
		delete[] _consumer;
		delete[] _tableUsed;
	}

	// ��� �Լ�
	void getInfo();					 // �Ĵ��� ���� ��� �Լ�
	void setDays();					 // ��¥ ���� �Լ�
	void setCloseStore();			 // �Ĵ繮 �ݴ� �Լ�
	void ConsumerComming();   // �մ��� �湮�ϴ� �Լ�
	void ConsumerDistribution(); // ��� ���� �մ� �й� �Լ�
};

class KimbapHeavenTable
{
private:
	std::string*	_menu;			// ���̺� ������ ����
	int				_state;			// 0 : û�� 1 : �Ļ��� 2 : ������ 3 : �ֹ���
public:

	KimbapHeavenTable()
		: _state(0)
	{
		_menu = new std::string[MENUARR];
	}

	~KimbapHeavenTable()
	{
		delete _menu;
	}

	// ��� �Լ�
	void TablePrint(int cnt, int* consumer);	// ���̺� ��� �Լ�
	void HaveAFinish(KimbapHeavenManager* manager);				// �Ļ縦 ��ġ�� �Լ�
};

