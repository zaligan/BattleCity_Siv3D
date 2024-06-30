#pragma once
#include <Siv3D.hpp>

namespace WindowSettings
{
	/// @brief 画面の拡大率
	static constexpr int32 pixelScale = 4;

	/// @brief ウィンドウの設定を行います
	inline void SetWindow()
	{
		Window::SetStyle(WindowStyle::Sizable);
		Window::SetTitle(U"BattleCity");
		Scene::SetResizeMode(ResizeMode::Keep);
		Scene::Resize(256 * pixelScale, 224 * pixelScale);
		Window::Resize(Size{ 960, 840 });
	}
}
