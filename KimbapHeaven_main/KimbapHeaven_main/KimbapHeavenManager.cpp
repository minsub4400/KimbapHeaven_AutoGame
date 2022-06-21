#include "KimbapHeavenManager.h"

void KimbapHeavenManager::getInfo()
{
	_time = clock() / 1000;  // 시간 업데이트
	std::cout << "식당 상태 : " << _openStore << " 날짜 : " << _days << " 시간 : " << _time << std::endl;
	std::cout << "번 돈(Month) : " << _getMoney << " 방문 누적 손님 : " << _visitor << std::endl;
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
