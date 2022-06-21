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
};

class KimbapHeavenTable : public KimbapHeavenManager
{
private:
	int				_count;			// ���̺� ��
	int				_consumer;		// ���̺� ������ �մ� ��
	std::string*	_menu;			// ���̺� ������ ����
	int				_state;			// 0 : û�� 1 : �Ļ��� 2 : ������ 3 : �ֹ���

public:
	KimbapHeavenTable(int tableCount)
		: _consumer(_visitor), _state(0), _count(tableCount)
	{
		_menu = new std::string;
	}

	~KimbapHeavenTable()
	{
		delete _menu;
	}

	// ��� �Լ�
	void TablePrint();				// ���̺� ��� �Լ�
	
};

