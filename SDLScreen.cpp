#include "SDLScreen.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

using namespace engine::SDL;

MockupScreen::MockupScreen()
{
	int flags = SDL_WINDOW_SHOWN;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw std::runtime_error(SDL_GetError());
	}

	if (SDL_CreateWindowAndRenderer(128, 64, flags, &window, &renderer))
	{
		return;
	}

	puts("Mockup screen created");
}

MockupScreen::~MockupScreen()
{
	if (nullptr != renderer)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	if (nullptr != window)
	{
		SDL_DestroyWindow(window);
		window = NULL;
	}

	SDL_Quit();

	puts("Mockup screen destroyed");
}

engine::utils::SharedPtr<MockupScreen> MockupScreen::GetInstance()
{
	static auto instance = utils::SharedPtr<MockupScreen>::Make();
	return instance;
}

void MockupScreen::Draw(int16_t x, int16_t y, Color color)
{
	uint8_t clr;

	switch (color)
	{
		default:
		case Color::Black:
			clr = 0;
			break;

		case Color::White:
			clr = 255;
			break;

		case Color::Transparent:
			return;

		case Color::Invert:
			return;
	}

	SDL_SetRenderDrawColor(renderer, clr, clr, clr, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(renderer, x, y);
}

void MockupScreen::Draw(const Drawable &dr, int16_t x, int16_t y, Color color)
{
	for (auto &&pixel : dr.pixels)
	{
		Draw(x + pixel.x, y + pixel.y, color);
	}
}

void MockupScreen::Clear(Color color)
{
	uint8_t clr;

	switch (color)
	{
		default:
		case Color::Black:
			clr = 0;
			break;

		case Color::White:
			clr = 255;
			break;

		case Color::Transparent:
			return;

		case Color::Invert:
			return;
	}

	SDL_SetRenderDrawColor(renderer, clr, clr, clr, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void MockupScreen::Render()
{
	SDL_RenderPresent(renderer);
}
