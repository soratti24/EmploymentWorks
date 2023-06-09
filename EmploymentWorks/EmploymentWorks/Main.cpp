//////////////////////////////////
// Main.cpp
// 
// 作成日：2023/06/09
//////////////////////////////////

//=== インクルード部 ===
#include "System.h"

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("EmploymentWorks"));

	srand(static_cast<unsigned int>(time(nullptr)));

	while (DispatchWindowMessage()) {
		//=== 更新処理


		//=== レンダリング開始処理


		//=== レンダリング終了処理
	}

	return 0;
}