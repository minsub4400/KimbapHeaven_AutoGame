#pragma once
#include <string>
#include <iostream>
#include "kitchen.h"
using namespace std;
#define STATE 3
#define MENU_NUM 10

// 알바
// 속성 : 상태, 하고 있는 일, 다음 할 일
// 행동 : 주문 오더, 테이블 청소
class Alba
{
protected:
public:
	int _state; // 0 : 주문 오더, 1 : 테이블 청소 중, 2 : 계산 중
	string* _nowAction;
	string* _nextAction;

	Alba()
		: _state(0)
	{	// 앞에 몇 번 테이블 번호 붙이기
		_nowAction = new string[STATE] { "주문 오더", "테이블 청소 중", "계산 중" };
		_nextAction = new string[STATE] { "주문 오더", "테이블 청소 중", "계산 중" };
	}
	Alba(const Alba& copyAlba) // 복사 생성자를 사용해보자~ (깊은 복사)
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

	int Order(Kitchen *menu);			// 메뉴 주문
	void TableCleen();						// 테이블 청소

};

