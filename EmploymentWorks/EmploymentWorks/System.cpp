//////////////////////////////////
// System.cpp
// 
// 作成日：2023/06/09
//////////////////////////////////


#include "System.h"


//=== グローバル変数部
HWND g_hWnd;	// ウィンドウハンドル。

///////////////////////////////////////////////////////////////////
// メッセージプロシージャ
///////////////////////////////////////////////////////////////////
LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 送られてきたメッセージで処理を分岐させる。
	switch (msg)
	{
	case WM_DESTROY:
		//スエンジンの破棄。
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}


///////////////////////////////////////////////////////////////////
// ウィンドウの初期化。
///////////////////////////////////////////////////////////////////
void InitWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
	//ウィンドウクラスのパラメータを設定(単なる構造体の変数の初期化です。)
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),		
		CS_CLASSDC,				// ウィンドウのスタイル。
		MsgProc,				// メッセージプロシージャ
		0,						
		0,						
		GetModuleHandle(NULL),	// このクラスのためのウインドウプロシージャがあるインスタンスハンドル
		NULL,					// アイコンのハンドル。アイコンを変えたい場合ここを変更する
		NULL,					// マウスカーソルのハンドル。NULLの場合はデフォルト
		NULL,					// ウィンドウの背景色。NULLの場合はデフォルト
		NULL,					// メニュー名
		appName,				// ウィンドウクラスに付ける名前
		NULL					
	};
	//ウィンドウクラスの登録。
	RegisterClassEx(&wc);

	// ウィンドウの作成。
	g_hWnd = CreateWindow(
		appName,				// 使用するウィンドウクラスの名前
		appName,				// ウィンドウの名前
		WS_OVERLAPPEDWINDOW,	// ウィンドウスタイル
		0,						// ウィンドウの初期X座標
		0,						// ウィンドウの初期Y座標
		SCREEN_WIDTH,			// ウィンドウの横幅
		SCREEN_HEIGHT,			// ウィンドウの縦幅
		NULL,					// 親ウィンドウ
		NULL,					// メニュー
		hInstance,				// アプリケーションのインスタンス
		NULL
	);

	ShowWindow(g_hWnd, nCmdShow);

}


//////////////////////////////////
// ゲームの初期化
//////////////////////////////////
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
	// ウィンドウを初期化
	InitWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow, appName);
}


/////////////////////////////////////////
// ウィンドウメッセージディスパッチ
/////////////////////////////////////////
bool DispatchWindowMessage()
{
	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		//ウィンドウからのメッセージを受け取る。
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//ウィンドウメッセージが空になった。
			break;
		}
	}
	return msg.message != WM_QUIT;
}