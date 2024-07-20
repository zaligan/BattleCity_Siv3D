#pragma once
#include <Siv3D.hpp>

namespace MapInfo {

	/// @brief マップのタイル数
	static constexpr int32 s_mapSize = 13;

	/// @brief 1タイルのサイズ(ピクセル)
	static constexpr Point s_tileSize = { 16, 16 };

	/// @brief マップの左上位置
	static constexpr Point s_mapBasePos = { 16, 8 };

	//1つ8*8ピクセル,　画面全体16*14タイル,マップは13*13タイル
	/// @brief map 0:空白 1:レンガ壁 2:旗
	static Grid<int32> s_map = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0 },
	};

	/// @brief マップのRect
	static Grid<Rect> s_mapRect = { s_mapSize, s_mapSize, Rect{ 0, 0, s_tileSize } };

	/// @brief レンガ壁のスプライトシートのインデックス
	static constexpr Point s_brickIndex = { 16, 0 };

	/// @brief 旗のスプライトシートのインデックス
	static constexpr Point s_flagIndex = { 19, 2 };
	
};
