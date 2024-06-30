# pragma once
# include <Siv3D.hpp>
# include "../Utils/TimeUtil.hpp"

// シーンの名前
enum class State
{
	Game
};

// シーン間で共有するデータ
struct GameData
{

};

using App = SceneManager<State, GameData>;
