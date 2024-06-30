#include "Game.hpp"

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
	Print << getSceneTime();
}

void Game::draw() const
{

}
