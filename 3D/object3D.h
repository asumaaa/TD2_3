#pragma once
#include "Windows.h"
#include "d3d12.h"
#include "dxgi1_6.h"
#include "cassert"
#include "vector"
#include "string"
#include "DirectXMath.h"
#include "assert.h"
#include "DirectXTex.h"
#include "wrl.h"
#include "Model.h"
#include "DirectXCommon.h"

using namespace DirectX;
using namespace Microsoft::WRL;
class Object3D
{
public:
	//�V���O���g���C���X�^���X
	Object3D* GetInstance();
	Object3D();
	~Object3D();
	void Initialize(ID3D12Device* device,Model* model);
	void Update(XMMATRIX& matView, XMMATRIX& matProjection);
	void Draw(ID3D12GraphicsCommandList* cmdList,D3D12_VERTEX_BUFFER_VIEW& vbView,D3D12_INDEX_BUFFER_VIEW& ibView);
	void Delete();
	//�Q�b�^�[�@�Z�b�^�[�@
	XMFLOAT3 GetPosition() { return position; };
	XMFLOAT3 GetRotation() { return rotation; };
	XMFLOAT3 GetScale() { return scale; };
	void setPosition(XMFLOAT3 pos);
	void setRotation(XMFLOAT3 rot);
	void setScale(XMFLOAT3 sca);
public:
	// �萔�o�b�t�@�p�f�[�^�\����B0
	struct ConstBufferDataB0
	{
		XMMATRIX mat;	// �R�c�ϊ��s��
	};
	// �萔�o�b�t�@�p�f�[�^�\����B1
	struct ConstBufferDataB1
	{
		XMFLOAT3 ambient;	//�A���r�G���g�W��
		float pad1;			//�p�f�B���O
		XMFLOAT3 diffuse;	//�f�B�t���[�Y�W��
		float pad2;			//�p�f�B���O
		XMFLOAT3 specular;	//�X�y�L�����[�W��
		float alpha;		//�A���t�@
	};
	//�萔�o�b�t�@�p�f�[�^�\���́i3D�ϊ��s��j
	/*struct ConstBufferDataTransform
	{
		XMMATRIX mat;
	};*/
private:
	//�萔�o�b�t�@�}�b�v
	/*ConstBufferDataTransform* constMapTransform;*/
	//���f��
	Model* model = nullptr;
	//�f�o�C�X
	/*DirectXCommon* dx = nullptr;*/
	ID3D12Device* device;
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuffB0; 
	ComPtr<ID3D12Resource> constBuffB1;
	// �R�}���h���X�g
	ID3D12GraphicsCommandList* cmdList;
private:
	//�A�t�B���ϊ����
	XMFLOAT3 scale = { 1,1,1 };
	XMFLOAT3 rotation = { 0,0,0};
	XMFLOAT3 position = { 0,0,0 };
	//���[���h�ϊ��s��
	XMMATRIX matWorld;
};