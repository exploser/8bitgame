#include "Sprite.hpp"
#include <sstream>

using namespace engine;

std::shared_ptr<IDrawable<bool>> engine::sprite::FromAscii(const std::string &str)
{
	using etype = decltype(FromAscii(""))::element_type;

	auto result = std::make_shared<etype>();
	std::stringstream ss(str);
	std::string line;
	etype::coord_type y = 0;

	while (std::getline(ss, line))
	{
		etype::coord_type x = 0;

		for (auto &&ch : line)
		{
			if (ch != ' ')
			{
				result->pixels.emplace_back(etype::Pixel{x, y /*, 1*/});
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
