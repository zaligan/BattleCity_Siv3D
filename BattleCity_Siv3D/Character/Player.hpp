#pragma once
#include <Siv3D.hpp>
#include "../MapManager.hpp"

class Player
{
public:
	Player(MapManager& mapManager);

	/// @brief プレイヤーの更新
	void update();

	/// @brief プレイヤーの描画
	void draw() const;

private:

	MapManager& m_mapManager;

	/// @brief スプライトシートのプレイヤーが映ったインデックス
	Point m_playerSpriteIndex = { 0, 0 };

	/// @brief キャタピラの動く間隔
	double m_spriteTimeInterval = 0.3;

	/// @brief 方向: (下: 0, 左: 1, 右: 2, 上: 3)
	int32 m_direction = 0;

	/// @brief プレイヤーの座標
	Vec2 m_playerPos = Vec2{ 4.0, 12.0 } * MapInfo::tileSize + MapInfo::mapBasePos;

	/// @brief プレイヤーのピクセル座標
	Point m_playerPixelPos = Point{ 0, 0 };

	/// @brief プレイヤ―の衝突範囲、壁のめり込み防止のため1ピクセル大きく
	Rect m_playerRect = Rect{ 0, 0, MapInfo::tileSize + Point{ 1, 1 } };

	/// @brief プレイヤーの移動速度
	double m_playerSpeed = 35.0;
};
