#pragma once
#include "DirectXMath.h"
#include "Input.h"
#include "WinApp.h"

using namespace DirectX;

//class Camera
//{
//public:
//	//�V���O���g���C���X�^���X
//	static Camera* GetInstance();
//	//�C���X�g���N�^ �f�X�g���N�^
//	Camera();
//	~Camera();
//	//������
//	void Initialize(Input* input, DXInput* dxInput,Player* player);
//	//�X�V
//	void Update();
//	void Update2();
//	void TitleUpdate();	//�^�C�g���̃J�����̏���
//	void MoveToGameUpdate();	//�^�C�g���̃J�����̏���
//	void Phase1RecollectionUpdate();	//�t�F�[�Y1�̃Q�[���n�܂�O�̏���
//	void GameClearUpdate();	//�t�F�[�Y1�̃Q�[���n�܂�O�̏���
//	//�v���C���[�̌������鋓��
//	void homind();
//	void TitleHomind();
//	//�Q�b�^�[�Z�b�^�[
//	void SetTarget(XMFLOAT3 pos);
//	void SetEye(XMFLOAT3 pos);
//	void SetGameClear();
//	XMFLOAT3 GetEye() { return eye_; };
//	XMFLOAT3 GetTraget() { return target_; };
//	XMFLOAT3 GetUp() { return up_; };
//	XMMATRIX GetMatProjection() { return matProjection_; };
//	XMMATRIX GetMatView() { return matView_; };
//private:
//	//�v���C���[
//	Player* player_;
//	//����
//	Input* input_;
//	DXInput* dxInput_;
//	//�ˉe�ϊ�
//	XMMATRIX matProjection_;
//	//�r���[�ϊ��s��
//	XMMATRIX matView_;
//	XMFLOAT3 eye_ = { -10, 10, 30 };
//	XMFLOAT3 target_ = { 0, 0, 0 };
//	XMFLOAT3 up_ = { 0, 1, 0 };
//	//�v���C���[�̌������鋓��
//	//�v���C���[�ƃJ�����̋���
//	float length_ = 40.0f;
//	float titleLength_ = 30.0f;
//	//���͂ɂ���ĉ��Z������ϐ�
//	float lengthX_ = 0.0f;
//	float lengthZ_ = 0.0f;
//
//	//�V�[���p
//	//�Q�[���Ɉڂ鎞�̃^�C�}�[
//	float moveToGameTimer_ = 0;
//
//	//�t�F�[�Y1�̃Q�[���n�܂�O�̃^�C�}�[
//	float phase1RecollectionTimer_ = 0;
//public:
//	void phase1RecollectionTimerReset() { phase1RecollectionTimer_ = 0; };
//};

