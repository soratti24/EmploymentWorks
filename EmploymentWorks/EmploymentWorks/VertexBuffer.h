//////////////////////////////////
// VertexBuffer.h
// 
// �쐬���F2023/06/09
//////////////////////////////////

#ifndef ___VERTEX_BUFFER_H___
#define ___VERTEX_BUFFER_H___

#include <d3d12.h>
#include "ComPtr.h"

//////////////////////////
// ���_�o�b�t�@�N���X
//////////////////////////
class VertexBuffer {
public:
	// �f�X�g���N�^
	~VertexBuffer();

	// ����������
	void Init(int size, int stride);

	// ���_�f�[�^�𒸓_�o�b�t�@�ɓK�p
	// @ Arg1 : ���_�f�[�^�Q
	void Write(void* vertices);

	// ���_�o�b�t�@�r���[���擾
	const D3D12_VERTEX_BUFFER_VIEW& GetView(void) const { return m_vertexBufferView; }

	// ���_�o�b�t�@�̗v�f�T�C�Y�����擾
	const UINT GetStrideInBytes(void) { return m_vertexBufferView.StrideInBytes; }

	// ���_�o�b�t�@�̑S�̃T�C�Y���擾
	const UINT GetSizeInBytes(void) { return m_vertexBufferView.SizeInBytes; }

	// ���\�[�X�̎擾
	const Coms::ComPtr<ID3D12Resource>& GetResource() const { return m_vertexBuffer; }

private:
	Coms::ComPtr<ID3D12Resource> m_vertexBuffer = nullptr;		// ���_�o�b�t�@
	D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView{};	// ���_�o�b�t�@�r���[
};

#endif //!___VERTEX_BUFFER_H___