#pragma once
#include <memory>
#include "BasicBWScreen.hpp"

namespace engine::SDL
{
class MockupScreen :
	public BasicBWScreen
{
	MockupScreen();
	virtual ~MockupScreen();

public:
	using BasicBWScreen::Draw;
	static std::shared_ptr<MockupScreen> GetInstance();
	virtual void Draw(coord_type x, coord_type y, color_type color) override;
	virtual void Render() override;
	virtual void Clear(color_type color) override;
};
}