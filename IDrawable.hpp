#pragma once
#include <cstdint>
#include <list>

#include "Vector2.hpp"

namespace engine
{
template <typename ColorT = uint8_t, typename CoordT = uint8_t>
struct IDrawable
{
	using color_type = ColorT;
	using coord_type = CoordT;

	struct Pixel
	{
		using color_type = ColorT;
		using coord_type = CoordT;

		Vector2<CoordT> coords;

		//ColorT color;
	};

	std::list<Pixel> pixels;
	Vector2<CoordT> size;
};
}
