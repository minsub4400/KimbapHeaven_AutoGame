#include "KimbapHeavenManager.h"

void KimbapHeavenManager::getInfo()
{
	_time = clock() / 1000;  // �ð� ������Ʈ
	std::cout << "�Ĵ� ���� : " << _openStore << " ��¥ : " << _days << " �ð� : " << _time << std::endl;
	std::cout << "�� ��(Month) : " << _getMoney << " �湮 ���� �մ� : " << _visitor << std::endl;
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
		std::cout << "���� ����!! �Ĵ� �� �ݽ��ϴ�." << std::endl;
		exit(0);
	}
}
