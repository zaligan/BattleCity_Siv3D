#include "Game.hpp"
#include "../WindowSettings.hpp"
#include "../MapInfo.hpp"

using namespace Util;
using namespace MapInfo;

// ゲームシーン
Game::Game(const InitData& init): IScene{ init }
{
	// シーン開始時、時間をリセット
	resetSceneTime();
	startSceneTimeCounter();

	m_mapManager.init();
}

void Game::update()
{
	m_player.update();
}

void Game::draw() const
{
	Rect { mapBasePos, tileSize * mapSize }.drawFrame(0, 1, Palette::Gray);

	{
		const ScopedRenderStates2D t2{ BlendState::Additive };

		m_mapManager.draw();

		m_player.draw();
	}

}
