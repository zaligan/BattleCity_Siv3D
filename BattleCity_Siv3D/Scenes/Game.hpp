#pragma once
#include "Common.hpp"

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

	static constexpr Point m_tileSize = { 16, 16 };

	Point m_playerSpriteIndex = { 0, 0 };

	double m_spriteTimeInterval = 0.3;
};
