#include "DirectXCommon.h"
#include "input.h"
#include "DirectXTex.h"
#include "object3D.h"
#include "list"
#include "memory"
#include "Texture.h"
#include "Model.h"
#include "Object3D.h"
#include "Sound.h"
#include "Camera.h"
#include "DXInput.h"
#include "Sprite.h"

class GameScene
{
	//�����o�֐�
public:
	GameScene();
	~GameScene();
	void Initialize(DirectXCommon* dxCommon, Input* input);
	void Initialize();
	void Update();
	void Draw();

	//�����o�ϐ�
private: 
	//�f�o�C�X��input
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	//�R���g���[��
	DXInput* dxInput = new DXInput();
};
