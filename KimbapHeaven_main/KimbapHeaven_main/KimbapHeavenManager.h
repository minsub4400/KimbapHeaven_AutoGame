#pragma once
#include <ctime>
#include <iostream>
#include <Windows.h>

class KimbapHeavenManager
{
private:
	bool	_openStore;		// 식당 오픈 유무 true - open, false - close
	int		_days;				// 날짜(일)
	int		_getMoney;		// 월(Month)에 번 돈
	int		_visitor;			// 방문객
	int		_time;				// 시간
public:
	KimbapHeavenManager()
		: _openStore(false), _days(1), _getMoney(0), _visitor(0), _time(0)
	{
		if (_openStore == false)
		{
			_openStore = true; // 식당문을 연다
		}
	}

	~KimbapHeavenManager()
	{
		// 소멸자 메모리 해제에만 쓰세염~
	}

	// 멤버 함수
	void getInfo();		    // 식당의 정보 출력 함수
	void setDays();		    // 날짜 변경 함수
	void setCloseStore(); // 식당문 닫는 함수
};

