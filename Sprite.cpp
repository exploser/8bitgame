#include "Sprite.hpp"
#include <sstream>

Sprite Sprite::FromAscii(const std::string &str)
{
	Sprite result;
	std::stringstream ss(str);
	std::string line;
	coord_type y = 0;

	while (std::getline(ss, line))
	{
		coord_type x = 0;

		for (auto &&ch : line)
		{
			if (ch != ' ')
			{
				result.pixels.emplace_back(Sprite::Pixel{x, y/*, 1*/});
			}

			++x;
		}

		if (y == 0 && line.empty())
		{
			continue;
		}

		++y;
	}

	return result;
}
