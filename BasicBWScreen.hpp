#pragma once
#include "IScreen.hpp"

struct BasicBWScreen :
	IScreen<bool>
{
    using IScreen<bool>::Draw;

    virtual void Draw(
		IDrawable<color_type, coord_type> *dr,
		coord_type x,
		coord_type y,
		color_type color) override
	{
		for (auto &&pixel : dr->pixels)
		{
			Draw(x + pixel.coords.x, y + pixel.coords.y, color);
		}
	}
};
