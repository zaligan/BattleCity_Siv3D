# pragma once
# include <Siv3D.hpp>
# include "IConfig.hpp"
# include "JSONParser.hpp"

struct SolidColorBackground : IConfig
{
	static constexpr StringView DataType = U"solidColorBackgrond";

	ColorF color{ 1.0,1.0,1.0,1.0 };

	SolidColorBackground() = default;

	explicit SolidColorBackground(const ColorF& color)
		:color(color) {}

	[[nodiscard]]
	StringView dataType() const override
	{
		return DataType;
	}

	[[nodiscard]]
	static std::unique_ptr<SolidColorBackground> Parse(const JSON& json)
	{
		if (const auto color = JSONParser::ReadColorF(json, U"color"))
		{
			return std::make_unique<SolidColorBackground>(*color);
		}
		else
		{
			return nullptr;
		}
	}
};

struct CircleObject :IConfig
{
	static constexpr StringView DataType = U"circleObject";

	Vec2 center{ 0,0 };

	double radius = 0;

	CircleObject() = default;

	CircleObject(const Vec2& center, double radius)
		:center(center), radius(radius) {}

	[[nodiscard]]
	StringView dataType() const override
	{
		return DataType;
	}

	[[nodiscard]]
	static std::unique_ptr<CircleObject> Parse(const JSON& json)
	{
		const auto center = JSONParser::ReadVec2(json, U"center");
		const auto radius = JSONParser::ReadDouble(json, U"radius");

		if (center && radius)
		{
			return std::make_unique<CircleObject>(*center, *radius);
		}
		else
		{
			return nullptr;
		}
	}
};

struct TestParsePrint :IConfig
{
	static constexpr StringView DataType = U"parseTest";

	int32 loopCount = 0;

	String text = U"fail";

	bool isPrinted = false;

	TestParsePrint() = default;

	TestParsePrint(int32 loopCount, const String& text, bool isPrinted)
		:loopCount(loopCount), text(text), isPrinted(isPrinted) {}

	[[nodiscard]]
	StringView dataType() const override
	{
		return DataType;
	}

	[[nodiscard]]
	static std::unique_ptr<TestParsePrint> Parse(const JSON& json)
	{
		const auto loopCount = JSONParser::ReadInt32(json, U"count");
		const auto text = JSONParser::ReadString(json, U"print");
		const auto isPrinted = JSONParser::ReadBool(json, U"displayable");

		// 全ての値が取得できた場合を書きたいが、boolの場合はfalseの場合もあるので、isPrintedがfalseの場合は無視する
		if (loopCount && text && isPrinted)
		{
			return std::make_unique<TestParsePrint>(*loopCount, *text, *isPrinted);
		}
		else
		{
			return nullptr;
		}
	}
};
