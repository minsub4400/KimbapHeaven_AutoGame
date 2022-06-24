#pragma once
#include <string>
#include <iostream>
#define MENU_ARR 10
using namespace std;


// ÁÖ¹æ
// ¼Ó¼º : ¸Þ´º
// Çàµ¿ : ¸¸µç´Ù
class Kitchen
{
protected:
public:
	string* _menu;

	Kitchen()
	{
		_menu = new string[MENU_ARR] {"ÂüÄ¡ ±è¹ä", "¶ó¸é", "µ·±î½º", "¿ìµ¿", "±èÄ¡ ººÀ½¹ä", "³Ã¸é", "³Ã¸ð¹Ð", "¶±ººÀÌ", "¼ø´ë", "Æ¢±è"};
	}

	~Kitchen()
	{
		delete[] _menu;
	}

	void MakeCooking();
};

