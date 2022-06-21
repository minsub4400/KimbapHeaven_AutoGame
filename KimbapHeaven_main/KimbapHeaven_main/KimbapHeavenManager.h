#pragma once
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <string>

#define MENUARR 10

class KimbapHeavenManager
{
private:
	bool	_openStore;			// 식당 오픈 유무 true - open, false - close
	int		_days;					// 날짜(일)
	int		_getMoney;			// 월(Month)에 번 돈
	int		_time;					// 시간
public:
	int		_visitor;				// 방문객
	int		_delayConsumer;   // 대기자
	KimbapHeavenManager() {}
	KimbapHeavenManager(int &visitorCount)
		: _openStore(false), _days(1), _getMoney(0), _visitor(visitorCount), _time(0), _delayConsumer(visitorCount)
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
	void getInfo();					// 식당의 정보 출력 함수
	void setDays();					// 날짜 변경 함수
	void setCloseStore();			// 식당문 닫는 함수
	void ConsumerComming();  // 손님이 방문하는 함수
};

class KimbapHeavenTable : public KimbapHeavenManager
{
private:
	int				_count;			// 테이블 수
	int				_consumer;		// 테이블에 배정된 손님 수
	std::string*	_menu;			// 테이블에 놓여진 음식
	int				_state;			// 0 : 청결 1 : 식사중 2 : 지저분 3 : 주문중

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

	// 멤버 함수
	void TablePrint();				// 테이블 출력 함수
	
};

