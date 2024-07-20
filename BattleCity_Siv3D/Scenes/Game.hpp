#pragma once
#include "Common.hpp"
#include "../Map.hpp"
#include "../MapManager.hpp"
#include "../Character/Player.hpp"

/// @brief ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	/// @brief シーンの更新を行います
	void update() override;

	/// @brief シーンの描画を行います
	void draw() const override;

private:

	/// @brief プレイヤー
	Player m_player;
};
