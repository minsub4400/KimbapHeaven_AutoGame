#pragma once
#include <string>
#include <iostream>
#define MENU_ARR 10
using namespace std;


// �ֹ�
// �Ӽ� : �޴�
// �ൿ : �����
class Kitchen
{
protected:
public:
	string* _menu;

	Kitchen()
	{
		_menu = new string[MENU_ARR] {"��ġ ���", "���", "���", "�쵿", "��ġ ������", "�ø�", "�ø��", "������", "����", "Ƣ��"};
	}

	~Kitchen()
	{
		delete[] _menu;
	}

	void MakeCooking();
};

