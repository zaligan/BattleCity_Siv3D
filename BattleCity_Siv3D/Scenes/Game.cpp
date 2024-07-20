#include "Game.hpp"
#include "../WindowSettings.hpp"

using namespace Util;
using namespace MapInfo;

// ゲームシーン
Game::Game(const InitData& init): IScene{ init }
{
	// シーン開始時、時間をリセット
	resetSceneTime();
	startSceneTimeCounter();

	for (int32 y = 0; y < s_mapSize; ++y)
	{
		for (int32 x = 0; x < s_mapSize; ++x)
		{
			s_mapRect[y][x].setPos(Point{ x * s_tileSize.x + s_mapBasePos.x, y * s_tileSize.y + s_mapBasePos.y });
		}
	}
	//Print << s_mapRect[12][5].pos;
}

void Game::update()
{
	m_player.update();

	for(auto& tile: s_mapRect)
	{
		tile.drawFrame(0, 1, Palette::Gray);
	}
}

void Game::draw() const
{
	Rect { s_mapBasePos, s_tileSize * s_mapSize }.drawFrame(0, 1, Palette::Gray);

	{
		const ScopedRenderStates2D t2{ BlendState::Additive };

		for (int32 y = 0; y < s_map.height(); ++y)
		{
			for (int32 x = 0; x < s_map.width(); ++x)
			{
				Point drawPos = Point{ x * s_tileSize.x + s_mapBasePos.x, y * s_tileSize.y + s_mapBasePos.y };
				switch (s_map[y][x])
				{
				case 0:
					break;
				case 1:
					TextureAsset(U"BattleCity")(s_brickIndex * s_tileSize, s_tileSize).draw(drawPos);
					break;
				case 2:
					TextureAsset(U"BattleCity")(s_flagIndex * s_tileSize, s_tileSize).draw(drawPos);
					break;
				default:
					break;
				}
			}
		}

		m_player.draw();
	}

}
