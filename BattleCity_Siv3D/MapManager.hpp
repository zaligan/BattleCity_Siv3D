#pragma once
#include <Siv3D.hpp>
#include "MapInfo.hpp"

/// @brief マップ管理クラス
class MapManager
{
public:
	MapManager() = default;

	void init();

	Grid<int32> getMap() const;

	Grid<Rect> getMapRects() const;

	void draw() const;


private:
	//1つ8*8ピクセル,　画面全体16*14タイル,マップは13*13タイル
	/// @brief map 0:空白 1:レンガ壁 2:旗
	Grid<int32> m_map = {
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
	Grid<Rect> m_mapRects = { MapInfo::mapSize, MapInfo::mapSize, Rect{ 0, 0, MapInfo::tileSize } };
};
