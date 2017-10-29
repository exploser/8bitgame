#pragma once
#include "Sprite.hpp"

namespace engine::sprite
{
inline namespace samples
{
static auto test = sprite::FromAscii(
	R"(
##### #####  #### #####
  #   #     #       #  
  #   #####  ###    #  
  #   #         #   #  
  #   ##### ####    #  
)"
	);
}
}
