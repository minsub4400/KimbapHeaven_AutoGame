#include "KimbapHeavenManager.h"

void KimbapHeavenManager::getInfo()
{
	_time = clock() / 1000;  // 시간 업데이트
	std::cout << "식당 상태 : " << _openStore << " 날짜 :  " << _days << "  시간 :  " << _time << std::endl;
	std::cout << "번 돈(Month) :  " << _getMoney << "  방문 누적 손님 :  " << _visitor << std::endl;
	std::cout << "대기 중인 손님 : " << _delayConsumer << std::endl;
}

int whileCount = 0;
void KimbapHeavenManager::setDays()
{
	whileCount++;
	if (whileCount == 300)
	{
		_days += 1;
		whileCount = 0;
	}
}

void KimbapHeavenManager::setCloseStore()
{
	if (_days == 10)
	{
		_openStore = false;
		std::cout << "영업 종료!! 식당 문 닫습니다." << std::endl;
		exit(0);
	}
}

int multiples = 30;
void KimbapHeavenManager::ConsumerComming()
{
	if (_time >= multiples) // 30초가 지날때 마다 손님이 랜덤으로 방문함
	{
		_delayConsumer += rand() % 10 + 1;
		multiples += 30;
		_visitor = _delayConsumer;
	}
}

int randDelay = 0;
void KimbapHeavenTable::ConsumerDistribution()
{
	if (_delayConsumer != 0) // 대기자가 존재하면
	{
		for (int i = 0; i < _count; i++) // 손님이 있는지 확인 함
		{
			if (_tableUsed[i] == false) // 손님이 비어 있으면 대기자를 랜덤으로 집어 넣음
			{
				randDelay = rand() % 5 + 1;
				_consumer[i] = _delayConsumer - randDelay;
			}
			else
			{
				// 아무것도 안함
			}
		}
	}
}

void KimbapHeavenTable::TablePrint()
{
	for (int i = 0; i < _count; i++)
	{
		std::cout << i + 1 << "번 테이블 " << "손님 수 :    " << _consumer[i] << "    음식 :    " << _menu[i] << "    상태 :    " << _state << std::endl;
	}
}
