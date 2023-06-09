//////////////////////////////////
// GraphicsEngine.h
// 
// �쐬���F2023/06/09
//////////////////////////////////

#ifndef ___GRAPHICS_ENGINE_H___
#define ___GRAPHICS_ENGINE_H___

//=== �C���N���[�h��
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>

////////////////////////////////////
// �O���t�B�b�N�X�G���W��
// @ Memo : DirectX12��p�ł�
////////////////////////////////////
class GraphicsEngine {
public:
	// �f�X�g���N�^
	~GraphicsEngine();


	// ������
	// @ Memo : �߂�l��true�̏ꍇ����������
	bool Init(HWND hWnd, UINT frameBufferWidth, UINT frameBufferHEIGHT);

	// �����_�����O�J�n����
	void BeginRender(void);

	// �����_�����O�I������
	void EndRender(void);

private:
};

#endif // !___GRAPHICS_ENGINE_H___
