#include "main.h"
#include "FPS.h"
#include "DXInput.h"
#include "fbxSDK.h"
#include "list"
#include "memory"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�E�B���h�E����
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"DirectX");

	Masage* masage;	//���b�Z�[�W
	masage = Masage::GetInstance();

	//DirectX����������
	DirectXCommon* dx = nullptr;
	dx = DirectXCommon::GetInstance();
	dx->Initialize(win);

	//�L�[�{�[�h
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	//�Q�[���V�[��
	GameScene* gameScene = nullptr;
	gameScene = new GameScene();
	gameScene->Initialize(dx, input);

	//FPS���Œ�
	FPS* fps = nullptr;
	fps = new FPS;
	fps->SetFrameRate(60.0f);
	fps->FpsControlBegin();;

	//FbxManager* fbx_manager = FbxManager::Create();
	//FbxImporter* fbx_importer = FbxImporter::Create(fbx_manager, "ImportTest");
	//FbxScene* fbx_scene = FbxScene::Create(fbx_manager, "SceneTest");
	//fbx_importer->Initialize("Box.fbx");
	//FbxNode* root_node = fbx_scene->GetRootNode();

	//for (int i = 0; i < root_node->GetNodeAttributeCount(); i++)
	//{
	//	FbxNodeAttribute* attribute = root_node->GetNodeAttributeByIndex(i);

	//	FbxNodeAttribute::EType type = attribute->GetAttributeType();

	//	printf("attribute type => %d\n", type);
	//}

	//for (int i = 0; i < root_node->GetChildCount(); i++)
	//{
	//	FbxNode* child = root_node->GetChild(i);
	//}

	//FbxGeometryConverter converter(fbx_manager);


	//// �|���S�����O�p�`�ɂ���
	//converter.Triangulate(fbx_scene, true);

	//// ���b�V��Node��T��
	//CollectMeshNode(fbx_scene->GetRootNode(), mesh_node_list);

	//void ObjFile::CollectMeshNode(FbxNode * node, std::map<std::string, FbxNode*>&list)
	//{
	//	for (int i = 0; i < node->GetNodeAttributeCount(); i++)
	//	{
	//		FbxNodeAttribute* attribute = node->GetNodeAttributeByIndex(i);

	//		// Attribute�����b�V���Ȃ�ǉ�
	//		if (attribute->GetAttributeType() == FbxNodeAttribute::EType::eMesh)
	//		{
	//			list[node->GetName()] = node;
	//			break;
	//		}
	//	}

	//	for (int i = 0; i < node->GetChildCount(); i++)
	//	{
	//		CollectMeshNode(node->GetChild(i), list);
	//	}
	//}


#pragma endregion

	//�Q�[�����[�v
	while (true)
	{
		//X�{�^���ŏI�����b�Z����������Q�[�����[�v�𔲂��� 
		if (masage->Update() == 1)break;

#pragma region DirectX���t���[������

		//�L�[�{�[�h�X�V
		input->Update();

		gameScene->Update();

		dx->PreDraw();
		// 4. �`��R�}���h
		gameScene->Draw();

		dx->PostDraw();

#pragma endregion
	}

	//FPS�Œ������
	dx->EndImgui();

	delete fps;
	delete gameScene;
	/*delete dx;*/

	masage->ExitGameloop();

	//�E�B���h�E�N���X��o�^����
	win->deleteWindow();

	return 0;
}