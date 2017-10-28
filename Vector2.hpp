#pragma once

template <typename CoordT>
struct Vector2
{
	using coord_type = CoordT;
	CoordT x;
	CoordT y;
};