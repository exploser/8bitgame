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

std::shared_ptr<MockupScreen> MockupScreen::GetInstance()
{
	static auto instance = std::shared_ptr<MockupScreen>(
		new MockupScreen,
		[](MockupScreen *ms)
	{
		delete ms;
	});
	return instance;
}

void MockupScreen::Draw(coord_type x, coord_type y, color_type color)
{
	uint8_t fcolor = color ? 255 : 0;
	SDL_SetRenderDrawColor(renderer, fcolor, fcolor, fcolor, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(renderer, x, y);
}

void MockupScreen::Clear(color_type color)
{
	uint8_t fcolor = color ? 255 : 0;
	SDL_SetRenderDrawColor(renderer, fcolor, fcolor, fcolor, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void MockupScreen::Render()
{
	SDL_RenderPresent(renderer);
}
