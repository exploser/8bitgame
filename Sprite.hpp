#pragma once
#include <string>

#include "IDrawable.hpp"

struct Sprite :
	IDrawable<bool>
{
	static Sprite FromAscii(const std::string &str);
};
