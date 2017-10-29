#pragma once
#include <cstdint>
#include <list>

#include "Vector2.hpp"

namespace engine
{
struct Drawable
{
	std::list<Vector2<int16_t>> pixels;
	Vector2<int16_t> size;
};
}
