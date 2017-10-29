#pragma once
#include <cstdint>

#include "IDrawable.hpp"

namespace engine
{
template <typename ColorT = uint8_t, typename CoordT = uint8_t>
struct IScreen
{
	using color_type = ColorT;
	using coord_type = CoordT;

	virtual ~IScreen()
	{
	}

	virtual void Draw(CoordT x, CoordT y, ColorT color) = 0;
	virtual void Draw(const IDrawable<ColorT, CoordT> &dr, CoordT x, CoordT y, ColorT color) = 0;
	virtual void Clear(ColorT color) = 0;
	virtual void Render() = 0;
};
}
