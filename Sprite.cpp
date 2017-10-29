#include "Sprite.hpp"
#include <sstream>

using namespace engine;

utils::SharedPtr<Drawable> engine::sprite::FromAscii(const std::string &str)
{
	auto result = utils::SharedPtr<Drawable>::Make();
	std::stringstream ss(str);
	std::string line;
	int16_t y = 0;

	while (std::getline(ss, line))
	{
		int16_t x = 0;

		for (auto &&ch : line)
		{
			if (ch != ' ')
			{
				result->pixels.emplace_back(Vector2<int16_t>{x, y});
			}

			result->size.x = std::max(result->size.x, ++x);
		}

		if (y == 0 && line.empty())
		{
			continue;
		}

		result->size.y = ++y;
	}

	return result;
}
