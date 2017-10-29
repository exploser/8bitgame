#pragma once
#include <string>

#include "Drawable.hpp"
#include "SharedPtr.hpp"

namespace engine::sprite
{
utils::SharedPtr<Drawable> FromAscii(const std::string &str);
}
