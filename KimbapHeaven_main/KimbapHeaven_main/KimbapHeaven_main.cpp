#include <iostream>
#include <ctime>
#include <Windows.h>
#include "KimbapHeavenManager.h"

int main()
{
	clock_t beforTime;		// 이전 시점 저장 변수
	clock_t currentTime;	// 현재 시점 저장 변수
	float deltaTime;		// 프레임 간격 저장 변수
	float s_deltaTime;
	int fpsCount = 0;		//
	beforTime = clock();
	// 클래스 인스턴스 생성
	KimbapHeavenManager manager; // 식당

    // 게임 루프
	while (true)
	{	

		// Input
		std::cout << "##### 김밥 천국 매니저!! #####" << std::endl;
		

		// Update
		

		// Render
		manager.setCloseStore(); //  식당 종료 호출
		manager.getInfo();			// 식당 정보 호출
		manager.setDays();		// 날짜 업데이트
		

		// 게임 프레임 조작----------------------------------------------------------
		currentTime = clock();
		deltaTime = (float)(currentTime - beforTime) / CLOCKS_PER_SEC;
		s_deltaTime = deltaTime;

		if (s_deltaTime >= 1.0f)
		{
			std::cout << " " << s_deltaTime << ", ";
			std::cout << "초당 프레임 : " << fpsCount << std::endl;
			if (fpsCount > 30)
			{
				fpsCount = 1;
			}
			fpsCount++;
		}
		else
		{
			// 아무것도 안함
		}
		// -------------------------------------------------------------------------------

		Sleep(s_deltaTime);
		system("cls");
	}
}