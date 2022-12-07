//#include "Camera.h"
//#include "Math.h"
//#define PI 3.14159265359
//
//Camera* Camera::GetInstance()
//{
//	static Camera instance;
//	return &instance;
//}
//
//Camera::Camera()
//{
//}
//
//Camera::~Camera()
//{
//}
//
//void Camera::Initialize(Input* input, DXInput* dxInput,Player* player)
//{
//	//��������󂯎�����f�[�^����
//	this->input_ = input;
//	this->dxInput_ = dxInput;
//	this->player_ = player;
//
//	//�ˉe�ϊ�
//	 matProjection_ = XMMatrixPerspectiveFovLH(
//		XMConvertToRadians(45.0f),			//�㉺��p45�x
//		(float)window_width / window_height,//�A�X�y�N�g��(��ʉ���/��ʗ���)
//		0.1f, 1000.0f						//�O�[�A���[
//	);
//
//	 //�s��v�Z
//	 matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//
//void Camera::Update()
//{
//	homind();
//	//�s��v�Z
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::Update2()
//{
//	float x = 0;
//	float y = 0;
//	float z = 0;
//
//	//�J�������v���C���[�̐^���Ɉړ�
//	x = player_->GetPosition1().x + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthX_) **/ cos(-player_->GetRotation().y - (PI / 2) + lengthX_) * length_);
//	y = player_->GetPosition1().y + (cos(-player_->GetRotation().x + (PI * 18 / 40)) * length_);
//	z = player_->GetPosition1().z + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthZ_) **/ sin(-player_->GetRotation().y - (PI / 2) + lengthZ_) * length_);
//
//
//	//�V��𒲐�
//	if (sin(-player_->GetRotation().x + (PI / 2)) <= 0)
//	{
//		up_ = { 0,-1,0 };
//	}
//	else
//	{
//		up_ = { 0,1,0 };
//	}
//	up_ = { 0,1,0 };
//
//	//�J�����̍��W�ɑ��
//	eye_ = { x,y,z };
//	//�����_���v���C���[�̍��W�ɂ���
//	target_ = { player_->GetPosition1().x ,player_->GetPosition1().y,player_->GetPosition1().z };
//	//�s��v�Z
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::TitleUpdate()
//{
//	TitleHomind();
//	//�s��v�Z
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::MoveToGameUpdate()
//{
//	//�^�C�}�[�n��
//	moveToGameTimer_++;
//
//	//��������ʂ̊O�ɏo������܂ŉˋ�̎��@���z�[�~���O
//	if (moveToGameTimer_ < 280)
//	{
//		TitleHomind();
//	}
//
//	if (moveToGameTimer_ >= 280 && moveToGameTimer_ <= 400)
//	{
//		target_.y += 8;
//		eye_.y += 7;
//	}
//
//	//�s��v�Z
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::Phase1RecollectionUpdate()
//{
//	//eye�̏����ʒu���Z�b�g
//	if (phase1RecollectionTimer_ == 0)
//	{
//		eye_ = { -100, -30, -80 };
//		target_ = { -30, 0, 0 };
//	}
//
//	phase1RecollectionTimer_++;
//
//	if (phase1RecollectionTimer_ < 480)
//	{
//		eye_.x += 0.4;
//		eye_.y += 0.2;
//		eye_.z -= 0.2;
//
//		target_.x += 0.1;
//	}
//
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::GameClearUpdate()
//{
//	eye_.x += 0.1;
//	target_.x += 0.1;
//	eye_.y += 0.1;
//	target_.y += 0.1;
//	matView_ = XMMatrixLookAtLH(XMLoadFloat3(&eye_), XMLoadFloat3(&target_), XMLoadFloat3(&up_));
//}
//
//void Camera::homind()
//{
//	//���E
//	float addX = dxInput_->GamePad.state.Gamepad.sThumbRX / (32767.0f) * (PI / 90);
//	float moveRange = PI;
//	if (dxInput_->GamePad.state.Gamepad.sThumbRX > 15000 || dxInput_->GamePad.state.Gamepad.sThumbRX < -15000)
//	{
//		if (lengthX_ < moveRange && lengthX_ > -moveRange)
//		{
//			lengthX_ -= addX;
//			lengthZ_ -= addX;
//		}
//		if (lengthX_ > moveRange)
//		{
//			lengthX_ = moveRange - addX;
//			lengthZ_ = moveRange - addX;
//		}
//		if (lengthX_ < -moveRange)
//		{
//			lengthX_ = -moveRange - addX;
//			lengthZ_ = -moveRange - addX;
//		}
//	}
//	//�X�e�b�N�ɐG���Ă��Ȃ��Ƃ��̏���
//	else if (lengthX_ != 0)
//	{
//		if (lengthX_ < -(PI / 90))
//		{
//			lengthX_ += (PI / 90);
//			lengthZ_ += (PI / 90);
//		}
//		else if (lengthX_ > (PI / 90))
//		{
//			lengthX_ -= (PI / 90);
//			lengthZ_ -= (PI / 90);
//		}
//	}
//
//	float x = 0;
//	float y = 0;
//	float z = 0;
//
//	//�J�������v���C���[�̐^���Ɉړ�
//	x = player_->GetPosition1().x + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthX_) **/ cos(-player_->GetRotation().y - (PI / 2) + lengthX_) * length_);
//	y = player_->GetPosition1().y + (cos(-player_->GetRotation().x + (PI * 18 / 40)) * length_);
//	z = player_->GetPosition1().z + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthZ_) **/ sin(-player_->GetRotation().y - (PI / 2) + lengthZ_) * length_);
//
//
//	//�V��𒲐�
//	if (sin(-player_->GetRotation().x + (PI / 2)) <= 0)
//	{
//		up_ = { 0,-1,0 };
//	}
//	else
//	{
//		up_ = { 0,1,0 };
//	}
//	up_ = { 0,1,0 };
//
//	//�J�����̍��W�ɑ��
//	eye_ = { x,y,z };
//	//�����_���v���C���[�̍��W�ɂ���
//	target_ = { player_->GetPosition1().x ,player_->GetPosition1().y,player_->GetPosition1().z };
//}
//
//void Camera::TitleHomind()
//{
//	//���E
//	float addX = dxInput_->GamePad.state.Gamepad.sThumbRX / (32767.0f) * (PI / 90);
//	float moveRange = PI / 3;
//	if (dxInput_->GamePad.state.Gamepad.sThumbRX > 15000 || dxInput_->GamePad.state.Gamepad.sThumbRX < -15000)
//	{
//		if (lengthX_ < moveRange && lengthX_ > -moveRange)
//		{
//			lengthX_ -= addX;
//			lengthZ_ -= addX;
//		}
//		if (lengthX_ > moveRange)
//		{
//			lengthX_ = moveRange - addX;
//			lengthZ_ = moveRange - addX;
//		}
//		if (lengthX_ < -moveRange)
//		{
//			lengthX_ = -moveRange - addX;
//			lengthZ_ = -moveRange - addX;
//		}
//	}
//	//�X�e�b�N�ɐG���Ă��Ȃ��Ƃ��̏���
//	else if (lengthX_ != 0)
//	{
//		if (lengthX_ < -(PI / 90))
//		{
//			lengthX_ += (PI / 90);
//			lengthZ_ += (PI / 90);
//		}
//		else if (lengthX_ > (PI / 90))
//		{
//			lengthX_ -= (PI / 90);
//			lengthZ_ -= (PI / 90);
//		}
//	}
//
//	float x = 0;
//	float y = 0;
//	float z = 0;
//
//	//�J�������v���C���[�̐^���Ɉړ�
//	x = player_->GetPosition1().x + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthX_) **/ cos(-player_->GetRotation().y - (PI * 0.8) + lengthX_) * titleLength_);
//	y = player_->GetPosition1().y + (cos(-player_->GetRotation().x + (PI * 15 / 40)) * titleLength_);
//	z = player_->GetPosition1().z + (/*sin(-player_->GetRotation().x + (PI / 2) + lengthZ_) **/ sin(-player_->GetRotation().y - (PI * 0.8) + lengthZ_) * titleLength_);
//
//
//	//�V��𒲐�
//	if (sin(-player_->GetRotation().x + (PI / 2)) <= 0)
//	{
//		up_ = { 0,-1,0 };
//	}
//	else
//	{
//		up_ = { 0,1,0 };
//	}
//	up_ = { 0,1,0 };
//
//	//�J�����̍��W�ɑ��
//	eye_ = { x,y,z };
//	//�����_���v���C���[�̍��W�ɂ���
//	target_ = { player_->GetPosition1().x ,player_->GetPosition1().y,player_->GetPosition1().z };
//}
//
//void Camera::SetTarget(XMFLOAT3 pos)
//{
//	target_ = pos;
//}
//
//void Camera::SetEye(XMFLOAT3 pos)
//{
//	eye_ = pos;
//}
//
//void Camera::SetGameClear()
//{
//	eye_ = { -60,20,-150 };
//	target_ = { -20,0,0 };
//}
