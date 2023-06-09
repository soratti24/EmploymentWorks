//////////////////////////////////
// System.cpp
// 
// �쐬���F2023/06/09
//////////////////////////////////


#include "System.h"


//=== �O���[�o���ϐ���
HWND g_hWnd;	// �E�B���h�E�n���h���B

///////////////////////////////////////////////////////////////////
// ���b�Z�[�W�v���V�[�W��
///////////////////////////////////////////////////////////////////
LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// �����Ă������b�Z�[�W�ŏ����𕪊򂳂���B
	switch (msg)
	{
	case WM_DESTROY:
		//�X�G���W���̔j���B
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}


///////////////////////////////////////////////////////////////////
// �E�B���h�E�̏������B
///////////////////////////////////////////////////////////////////
void InitWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
	//�E�B���h�E�N���X�̃p�����[�^��ݒ�(�P�Ȃ�\���̂̕ϐ��̏������ł��B)
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),		
		CS_CLASSDC,				// �E�B���h�E�̃X�^�C���B
		MsgProc,				// ���b�Z�[�W�v���V�[�W��
		0,						
		0,						
		GetModuleHandle(NULL),	// ���̃N���X�̂��߂̃E�C���h�E�v���V�[�W��������C���X�^���X�n���h��
		NULL,					// �A�C�R���̃n���h���B�A�C�R����ς������ꍇ������ύX����
		NULL,					// �}�E�X�J�[�\���̃n���h���BNULL�̏ꍇ�̓f�t�H���g
		NULL,					// �E�B���h�E�̔w�i�F�BNULL�̏ꍇ�̓f�t�H���g
		NULL,					// ���j���[��
		appName,				// �E�B���h�E�N���X�ɕt���閼�O
		NULL					
	};
	//�E�B���h�E�N���X�̓o�^�B
	RegisterClassEx(&wc);

	// �E�B���h�E�̍쐬�B
	g_hWnd = CreateWindow(
		appName,				// �g�p����E�B���h�E�N���X�̖��O
		appName,				// �E�B���h�E�̖��O
		WS_OVERLAPPEDWINDOW,	// �E�B���h�E�X�^�C��
		0,						// �E�B���h�E�̏���X���W
		0,						// �E�B���h�E�̏���Y���W
		SCREEN_WIDTH,			// �E�B���h�E�̉���
		SCREEN_HEIGHT,			// �E�B���h�E�̏c��
		NULL,					// �e�E�B���h�E
		NULL,					// ���j���[
		hInstance,				// �A�v���P�[�V�����̃C���X�^���X
		NULL
	);

	ShowWindow(g_hWnd, nCmdShow);

}


//////////////////////////////////
// �Q�[���̏�����
//////////////////////////////////
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
	// �E�B���h�E��������
	InitWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow, appName);
}


/////////////////////////////////////////
// �E�B���h�E���b�Z�[�W�f�B�X�p�b�`
/////////////////////////////////////////
bool DispatchWindowMessage()
{
	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		//�E�B���h�E����̃��b�Z�[�W���󂯎��B
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//�E�B���h�E���b�Z�[�W����ɂȂ����B
			break;
		}
	}
	return msg.message != WM_QUIT;
}