#pragma once
#include "dxgidebug.h"
#include <d3d12.h>

class Masage
{
public:
	static Masage* GetInstance();
	bool Update();
	//X�{�^���ŏI�����b�Z����������Q�[�����[�v�𔲂��� 
	bool ExitGameloop();
public:
	MSG msg{};
};

