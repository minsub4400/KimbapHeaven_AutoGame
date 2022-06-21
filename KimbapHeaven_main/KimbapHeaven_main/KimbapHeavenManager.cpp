#include "KimbapHeavenManager.h"

void KimbapHeavenManager::getInfo()
{
	_time = clock() / 1000;  // �ð� ������Ʈ
	std::cout << "�Ĵ� ���� : " << _openStore << " ��¥ :  " << _days << "  �ð� :  " << _time << std::endl;
	std::cout << "�� ��(Month) :  " << _getMoney << "  �湮 ���� �մ� :  " << _visitor << std::endl;
	std::cout << "��� ���� �մ� : " << _delayConsumer << std::endl;
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

int multiples = 30;
void KimbapHeavenManager::ConsumerComming()
{
	if (_time >= multiples) // 30�ʰ� ������ ���� �մ��� �������� �湮��
	{
		_delayConsumer += rand() % 10 + 1;
		multiples += 30;
		_visitor = _delayConsumer;
	}
}

int randDelay = 0;
void KimbapHeavenTable::ConsumerDistribution()
{
	if (_delayConsumer != 0) // ����ڰ� �����ϸ�
	{
		for (int i = 0; i < _count; i++) // �մ��� �ִ��� Ȯ�� ��
		{
			if (_tableUsed[i] == false) // �մ��� ��� ������ ����ڸ� �������� ���� ����
			{
				randDelay = rand() % 5 + 1;
				_consumer[i] = _delayConsumer - randDelay;
			}
			else
			{
				// �ƹ��͵� ����
			}
		}
	}
}

void KimbapHeavenTable::TablePrint()
{
	for (int i = 0; i < _count; i++)
	{
		std::cout << i + 1 << "�� ���̺� " << "�մ� �� :    " << _consumer[i] << "    ���� :    " << _menu[i] << "    ���� :    " << _state << std::endl;
	}
}
