//////////////////////////////////
// Main.cpp
// 
// �쐬���F2023/06/09
//////////////////////////////////

//=== �C���N���[�h�� ===
#include "System.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐�
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("EmploymentWorks"));

	srand(static_cast<unsigned int>(time(nullptr)));

	while (DispatchWindowMessage()) {
		//=== �X�V����


		//=== �����_�����O�J�n����


		//=== �����_�����O�I������
	}

	return 0;
}