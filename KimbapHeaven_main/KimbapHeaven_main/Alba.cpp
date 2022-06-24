#include "Alba.h"

int Alba::Order(Kitchen *menu)
{
	int randMenu = 0;
	randMenu = rand() % MENU_NUM;
	cout << menu->_menu[randMenu] << " ¿À´Ù ~" << endl;;
	return randMenu;
}

void Alba::TableCleen()
{

}
