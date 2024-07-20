#include "MapManager.hpp"

using namespace MapInfo;

void MapManager::init()
{
	for (int32 y = 0; y < mapSize; ++y)
	{
		for (int32 x = 0; x < mapSize; ++x)
		{
			m_mapRects[y][x].setPos(Point{ x * tileSize.x + mapBasePos.x, y * tileSize.y + mapBasePos.y });
		}
	}
}

Grid<int32> MapManager::getMap() const
{
	return m_map; 
}

Grid<Rect> MapManager::getMapRects() const
{
	return m_mapRects; 
}

void MapManager::draw() const
{
	for (int32 y = 0; y < mapSize; ++y)
	{
		for (int32 x = 0; x < mapSize; ++x)
		{
			Point drawPos = Point{ x * tileSize.x + mapBasePos.x, y * tileSize.y + mapBasePos.y };
			switch (m_map[y][x])
			{
			case 0:
				break;
			case 1:
				TextureAsset(U"BattleCity")(brickIndex * tileSize, tileSize).draw(drawPos);
				break;
			case 2:
				TextureAsset(U"BattleCity")(flagIndex * tileSize, tileSize).draw(drawPos);
				break;
			default:
				break;
			}
		}
	}
}
