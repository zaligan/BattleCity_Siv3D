#include "Player.hpp"
#include "../Utils/TimeUtil.hpp"
#include "../Map.hpp"

using namespace Util;
using namespace MapInfo;

Player::Player()
{
}

void Player::update()
{
	Print << s_mapRect[12][5].pos;
	// プレイヤーのテクスチャ更新
	m_playerSpriteIndex.x = static_cast<int32_t>(std::fmod(getSceneTime() / m_spriteTimeInterval, 2));

	Vec2 moveDirection = Vec2{ 0, 0 };
	// 操作入力受付
	if (KeyRight.pressed())
	{
		moveDirection.x = 1;
		m_direction = 3;
	}
	else if (KeyLeft.pressed())
	{
		moveDirection.x = -1;
		m_direction = 1;
	}
	else if (KeyDown.pressed())
	{
		moveDirection.y = 1;
		m_direction = 2;
	}
	else if (KeyUp.pressed())
	{
		moveDirection.y = -1;
		m_direction = 0;
	}

	// プレイヤーと壁の衝突判定をするためのRectを作成
	Rect right{ m_playerPixelPos.x + s_tileSize.x, m_playerPixelPos.y, 1, s_tileSize.y };
	Rect left{ m_playerPixelPos.x - 1, m_playerPixelPos.y, 1, s_tileSize.y };
	Rect bottom{ m_playerPixelPos.x, m_playerPixelPos.y + s_tileSize.y, s_tileSize.x, 1 };
	Rect top{ m_playerPixelPos.x, m_playerPixelPos.y - 1, s_tileSize.x, 1 };

	// 次に移動するタイルが壁かどうか判定
	for (auto i = 0; i < s_map.height(); i++)
	{
		for (auto j = 0; j < s_map.width(); j++)
		{
			if (s_map[i][j] != 1) continue;
			
			if (s_mapRect[i][j].intersects(right) && 1 <= moveDirection.x)
			{
				moveDirection.x = 0;
			}
			if (s_mapRect[i][j].intersects(left) && moveDirection.x <= -1)
			{
				moveDirection.x = 0;
			}
			if (s_mapRect[i][j].intersects(bottom) && 1 <= moveDirection.y)
			{
				moveDirection.y = 0;
			}
			if (s_mapRect[i][j].intersects(top) && moveDirection.y <= -1)
			{
				moveDirection.y = 0;
			}

		}
	}

	// プレイヤーの座標を更新
	m_playerPos += moveDirection * m_playerSpeed * getDeltaTime();
	m_playerPixelPos = Point{ int32(m_playerPos.x), int32(m_playerPos.y) };

	// プレイヤーの座標をマップの範囲内に収める
	m_playerPos = m_playerPos.clamp(Rect{ s_mapBasePos, s_mapSize * s_tileSize - m_playerRect.size });

	// プレイヤーの衝突範囲を更新
	m_playerRect.setPos(m_playerPixelPos);
}

void Player::draw() const
{
	switch (m_direction)
	{
	case 0:
		TextureAsset(U"BattleCity")(m_playerSpriteIndex * s_tileSize, s_tileSize).draw(m_playerPixelPos);
		break;
	case 1:
		TextureAsset(U"BattleCity")((m_playerSpriteIndex + Point{ 2, 0 }) * s_tileSize, s_tileSize).draw(m_playerPixelPos);
		break;
	case 2:
		TextureAsset(U"BattleCity")((m_playerSpriteIndex + Point{ 4, 0 }) * s_tileSize, s_tileSize).draw(m_playerPixelPos);
		break;
	case 3:
		TextureAsset(U"BattleCity")((m_playerSpriteIndex + Point{ 6, 0 }) * s_tileSize, s_tileSize).draw(m_playerPixelPos);
		break;

	default:
		break;
	}
}
