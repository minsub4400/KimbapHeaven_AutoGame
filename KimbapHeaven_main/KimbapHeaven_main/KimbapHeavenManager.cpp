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
	if (_time >= multiples) // 30�ʰ� ������ ����
	{ 
		_delayConsumer += rand() % 5 + 1;  // 1 ~ 5�� ������ �մ�
		multiples += 30;
		_visitor += _delayConsumer; 
	}
	ConsumerDistribution(); // �մ� �й�
	getInfo();						  // �Ĵ� ���� ȣ��
}

int randDelay = 0;
void KimbapHeavenManager::ConsumerDistribution()
{
	if (_delayConsumer != 0) // ����ڰ� �����ϸ�
	{
		for (int i = 0; i < _count; i++) // ���̺� �� ��ŭ �ݺ���
		{
			if (_tableUsed[i] == false) // ���̺� �մ��� ��� ������ ����ڸ� �������� ���� ����
			{
				randDelay = rand() % (_delayConsumer + 1); // ���̺� ���� ���� �ο� �̱� ����
				_consumer[i] = randDelay; // �������� ���� �մ��� ���̺� ���� ����
				_delayConsumer -= randDelay; // ������� �մԿ��� ���̺� ���� ���� ��� ���� ��
				if (_delayConsumer < 0) // ����� ���� ������ �Ǹ� 0���� �ʱ�ȭ ��Ŵ
				{
					_delayConsumer = 0; 
				}
				_tableUsed[i] = true; // ���̺� �մ��� �Լ��� ��� ���̺� ����� true�� �ٲ�.
			}
			else
			{
				// _tableUsed�� true�� �ƹ��͵� ����
			}
		}
	}
}

void KimbapHeavenTable::TablePrint(int cnt, int *consumer)
{
	for (int i = 0; i < cnt; i++)
	{
		std::cout << i + 1 << "�� ���̺� " << "�մ� �� :    " << consumer[i] << "    ���� :    " << _menu[i] << "    ���� :    " << _state << std::endl;
	}
}

int finishTime = 10;
void KimbapHeavenTable::HaveAFinish(KimbapHeavenManager *manager)
{
	if (manager->_time > finishTime) // 10�ʰ� ������
	{
		finishTime + 10; // 10�ʾ� ����
		for (int i = 0; i < manager->_count; i++)
		{
			manager->_tableUsed[i] = false;
		}
	}
	// _time�� 10�ʰ� ������ ���� ���̺�1, 2, 3�����.
}
