#pragma once
#include <Siv3D.hpp>

/// @brief マップに関する情報
namespace MapInfo {

	/// @brief マップのタイル数
	inline constexpr int32 mapSize = 13;

	/// @brief 1タイルのサイズ(ピクセル)
	inline constexpr Point tileSize = { 16, 16 };

	/// @brief マップの左上位置
	inline constexpr Point mapBasePos = { 16, 8 };

	/// @brief レンガ壁のスプライトシートのインデックス
	inline constexpr Point brickIndex = { 16, 0 };

	/// @brief 旗のスプライトシートのインデックス
	inline constexpr Point flagIndex = { 19, 2 };
	
};
