//////////////////////////////////
// System.h
// 
// �쐬���F2023/06/09
//////////////////////////////////


#ifndef ___SYSTEM_H___
#define ___SYSTEM_H___

//=== �C���N���[�h��
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

//=== �萔��
const int SCREEN_WIDTH = 960;	// �A�v���P�[�V�����E�B���h�E�̉���
const int SCREEN_HEIGHT = 540;	// �A�v���P�[�V�����E�B���h�E�̏c��

//=== �v���g�^�C�v�錾��
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName);
bool DispatchWindowMessage();

#endif // !___SYSTEM_H___
