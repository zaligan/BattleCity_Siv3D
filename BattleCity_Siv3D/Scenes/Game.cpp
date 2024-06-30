#include "Game.hpp"
#include "../WindowSettings.hpp"

using namespace Util;

// ゲームシーン
Game::Game(const InitData& init): IScene{ init }
{
	//シーン開始時、時間をリセット
	resetSceneTime();
	startSceneTimeCounter();
}

void Game::update()
{
	m_playerSpriteIndex.x = static_cast<int32_t>(std::fmod(getSceneTime() / m_spriteTimeInterval, 2));
}

void Game::draw() const
{
	const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };
	const ScopedRenderStates2D t2{ BlendState::Additive };

	TextureAsset(U"BattleCity")( m_playerSpriteIndex.x * m_tileSize.x, m_playerSpriteIndex.y * m_tileSize.y, m_tileSize.x, m_tileSize.y ).scaled(WindowSettings::pixelScale).draw(100, 100);
}
