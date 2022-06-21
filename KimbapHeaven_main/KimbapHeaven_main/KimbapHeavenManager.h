#pragma once
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <string>

#define MENUARR 10

class KimbapHeavenManager
{
private:
	bool	_openStore;			// �Ĵ� ���� ���� true - open, false - close
	int		_days;					// ��¥(��)
	int		_getMoney;			// ��(Month)�� �� ��
	int		_time;					// �ð�
public:
	int		_visitor;				// �湮��
	int		_delayConsumer;   // �����
	KimbapHeavenManager() {}
	KimbapHeavenManager(int &visitorCount)
		: _openStore(false), _days(1), _getMoney(0), _visitor(visitorCount), _time(0), _delayConsumer(visitorCount)
	{
		if (_openStore == false)
		{
			_openStore = true; // �Ĵ繮�� ����
		}
	}
	~KimbapHeavenManager()
	{
		// �Ҹ��� �޸� �������� ������~
	}

	// ��� �Լ�
	void getInfo();					// �Ĵ��� ���� ��� �Լ�
	void setDays();					// ��¥ ���� �Լ�
	void setCloseStore();			// �Ĵ繮 �ݴ� �Լ�
	void ConsumerComming();  // �մ��� �湮�ϴ� �Լ�
	//void ConsumerDistribution(KimbapHeavenTable tableUsed); // ��� ���� �մ� �й� �Լ�
};

class KimbapHeavenTable : public KimbapHeavenManager
{
private:
	std::string*	_menu;			// ���̺� ������ ����
	int				_state;			// 0 : û�� 1 : �Ļ��� 2 : ������ 3 : �ֹ���

public:
	int*			_consumer;		// ���̺� ������ �մ� ��
	int				_count;			// ���̺� ��
	bool*			_tableUsed;		// ���̺� ��� ����
	KimbapHeavenTable(int tableCount)
		: _state(0), _count(tableCount)
	{
		_consumer = new int[tableCount];
		_menu = new std::string;
		_tableUsed = new bool[tableCount];
	}

	~KimbapHeavenTable()
	{
		delete[] _consumer;
		delete[] _tableUsed;
		delete _menu;
	}

	// ��� �Լ�
	void TablePrint();				// ���̺� ��� �Լ�
	
};

