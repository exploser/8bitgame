#pragma once
#include <cstdint>

#include "Drawable.hpp"
#include "Color.hpp"

namespace engine
{
struct IScreen
{
	virtual ~IScreen()
	{
	}

	virtual void Draw(int16_t x, int16_t y, Color color) = 0;
	virtual void Draw(const Drawable &dr, int16_t x, int16_t y, Color color) = 0;
	virtual void Clear(Color color) = 0;
	virtual void Render() = 0;
};
}
