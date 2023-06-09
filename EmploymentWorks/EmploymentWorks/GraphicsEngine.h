//////////////////////////////////
// GraphicsEngine.h
// 
// 作成日：2023/06/09
//////////////////////////////////

#ifndef ___GRAPHICS_ENGINE_H___
#define ___GRAPHICS_ENGINE_H___

//=== インクルード部
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>

////////////////////////////////////
// グラフィックスエンジン
// @ Memo : DirectX12専用です
////////////////////////////////////
class GraphicsEngine {
public:
	// デストラクタ
	~GraphicsEngine();


	// 初期化
	// @ Memo : 戻り値がtrueの場合初期化成功
	bool Init(HWND hWnd, UINT frameBufferWidth, UINT frameBufferHEIGHT);

	// レンダリング開始処理
	void BeginRender(void);

	// レンダリング終了処理
	void EndRender(void);

private:
};

#endif // !___GRAPHICS_ENGINE_H___
