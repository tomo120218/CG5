#include "WorldTransformEx.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

void WorldTransformEx::UpdateMatrix() { 
	matWorld_ = MakeAffineMatrix();
	TransferMatrix();
}

// アフィン変換行列を作る
Matrix4x4 WorldTransformEx::MakeAffineMatrix() { 
	Matrix4x4 matScale = MakeScaleMatrix(scale_);
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotZ * matRotX * matRotY;
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);
	Matrix4x4 matWorld = matScale * matRot * matTrans;
	return matWorld;
}