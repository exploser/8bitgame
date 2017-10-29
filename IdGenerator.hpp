#pragma once
#include <cstdint>

namespace engine::utils
{
static uint16_t NextId()
{
	static uint16_t id;
	return ++id;
}
}
