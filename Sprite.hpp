#pragma once
#include <string>
#include <memory>

#include "IDrawable.hpp"

namespace engine::sprite
{
std::shared_ptr<IDrawable<bool>> FromAscii(const std::string &str);
}
