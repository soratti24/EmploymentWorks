//////////////////////////////////
// VertexBuffer.h
// 
// 作成日：2023/06/09
//////////////////////////////////

#ifndef ___VERTEX_BUFFER_H___
#define ___VERTEX_BUFFER_H___

#include <d3d12.h>
#include "ComPtr.h"

//////////////////////////
// 頂点バッファクラス
//////////////////////////
class VertexBuffer {
public:
	// デストラクタ
	~VertexBuffer();

	// 初期化処理
	void Init(int size, int stride);

	// 頂点データを頂点バッファに適用
	// @ Arg1 : 頂点データ群
	void Write(void* vertices);

	// 頂点バッファビューを取得
	const D3D12_VERTEX_BUFFER_VIEW& GetView(void) const { return m_vertexBufferView; }

	// 頂点バッファの要素サイズ幅を取得
	const UINT GetStrideInBytes(void) { return m_vertexBufferView.StrideInBytes; }

	// 頂点バッファの全体サイズを取得
	const UINT GetSizeInBytes(void) { return m_vertexBufferView.SizeInBytes; }

	// リソースの取得
	const Coms::ComPtr<ID3D12Resource>& GetResource() const { return m_vertexBuffer; }

private:
	Coms::ComPtr<ID3D12Resource> m_vertexBuffer = nullptr;		// 頂点バッファ
	D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView{};	// 頂点バッファビュー
};

#endif //!___VERTEX_BUFFER_H___