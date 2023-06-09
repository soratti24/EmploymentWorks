//////////////////////////////////
// System.h
// 
// 作成日：2023/06/09
//////////////////////////////////


#ifndef ___SYSTEM_H___
#define ___SYSTEM_H___

//=== インクルード部
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <d3d12.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <memory>
#include <vector>
#include <map>
#include <list>

//=== 定数部
const int SCREEN_WIDTH = 960;	// アプリケーションウィンドウの横幅
const int SCREEN_HEIGHT = 540;	// アプリケーションウィンドウの縦幅

//=== プロトタイプ宣言部
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName);
bool DispatchWindowMessage();

#endif // !___SYSTEM_H___
