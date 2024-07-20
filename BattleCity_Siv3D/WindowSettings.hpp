#pragma once
#include <Siv3D.hpp>

namespace WindowSettings
{
	/// @brief 画面の拡大率
	static constexpr int32 windowScale = 4;

	/// @brief ウィンドウの設定を行います
	inline void SetWindow()
	{
		Window::SetStyle(WindowStyle::Sizable);
		Window::SetTitle(U"BattleCity");
		Scene::SetResizeMode(ResizeMode::Keep);
		Scene::Resize(256, 224 );
		Window::Resize(256 * windowScale, 224 * windowScale);
	}
}
