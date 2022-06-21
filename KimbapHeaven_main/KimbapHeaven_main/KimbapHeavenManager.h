#pragma once
#include <ctime>
#include <iostream>
#include <Windows.h>

class KimbapHeavenManager
{
private:
	bool	_openStore;		// �Ĵ� ���� ���� true - open, false - close
	int		_days;				// ��¥(��)
	int		_getMoney;		// ��(Month)�� �� ��
	int		_visitor;			// �湮��
	int		_time;				// �ð�
public:
	KimbapHeavenManager()
		: _openStore(false), _days(1), _getMoney(0), _visitor(0), _time(0)
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
	void getInfo();		    // �Ĵ��� ���� ��� �Լ�
	void setDays();		    // ��¥ ���� �Լ�
	void setCloseStore(); // �Ĵ繮 �ݴ� �Լ�
};

