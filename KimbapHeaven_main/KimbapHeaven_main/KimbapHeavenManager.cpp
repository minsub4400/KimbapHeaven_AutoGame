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
	if (_time >= multiples) // 30초가 지날때 마다
	{ 
		_delayConsumer += rand() % 5 + 1;  // 1 ~ 5명 사이의 손님
		multiples += 30;
		_visitor += _delayConsumer; 
	}
	ConsumerDistribution(); // 손님 분배
	getInfo();						  // 식당 정보 호출
}

int randDelay = 0;
void KimbapHeavenManager::ConsumerDistribution()
{
	if (_delayConsumer != 0) // 대기자가 존재하면
	{
		for (int i = 0; i < _count; i++) // 테이블 수 만큼 반복함
		{
			if (_tableUsed[i] == false) // 테이블에 손님이 비어 있으면 대기자를 랜덤으로 집어 넣음
			{
				randDelay = rand() % (_delayConsumer + 1); // 테이블에 집어 넣을 인원 뽑기 사이
				_consumer[i] = randDelay; // 랜덤으로 나온 손님을 테이블에 집어 넣음
				_delayConsumer -= randDelay; // 대기중인 손님에서 테이블에 집어 넣은 사람 수를 뺌
				if (_delayConsumer < 0) // 대기자 수가 음수가 되면 0으로 초기화 시킴
				{
					_delayConsumer = 0; 
				}
				_tableUsed[i] = true; // 테이블에 손님이 입석된 경우 테이블 사용을 true로 바꿈.
			}
			else
			{
				// _tableUsed가 true면 아무것도 안함
			}
		}
	}
}

void KimbapHeavenTable::TablePrint(int cnt, int *consumer)
{
	for (int i = 0; i < cnt; i++)
	{
		std::cout << i + 1 << "번 테이블 " << "손님 수 :    " << consumer[i] << "    음식 :    " << _menu[i] << "    상태 :    " << _state << std::endl;
	}
}

int finishTime = 10;
void KimbapHeavenTable::HaveAFinish(KimbapHeavenManager *manager)
{
	if (manager->_time > finishTime) // 10초가 지나면
	{
		finishTime + 10; // 10초씩 더함
		for (int i = 0; i < manager->_count; i++)
		{
			manager->_tableUsed[i] = false;
		}
	}
	// _time이 10초가 지날떄 마다 테이블1, 2, 3비어짐.
}
