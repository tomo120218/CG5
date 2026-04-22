#include "GameScene.h"
#include "KamataEngine.h"
#include <Windows.h>
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3D_18_ビョウドウ_トモヒロ_AL3");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//DirectXCommonクラスが管理している、ウインドウの幅と高さの値の取得
	int32_t w = dxCommon->GetBackBufferWidth();
	int32_t h = dxCommon->GetBackBufferHeight();
	DebugText::GetInstance()->ConsolePrintf(std::format("Width: {}, height: {}\n, w, h").c_str());

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();

	// ゲームシーンの初期化
	gameScene->Initialize();

	// メインループ
	while (true) {

		// エンジンの更新
		if (KamataEngine::Update()) {

			break;
		}

		// ゲームシーンの更新
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;

	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了宣言
	KamataEngine::Finalize();

	return 0;
}
