#include "SDLScreen.hpp"

#include "Sprites.hpp"
#include "Scene.hpp"
#include "DrawableNode.hpp"

#include <string>
#include <sstream>
#include <thread>

using namespace std::literals;
using namespace engine;
using namespace engine::scene;

static auto test = sprite::FromAscii(
	R"(
 ####
##   ########
 # # # # # # ###
  #   #######   #
   #     #    #  #
   #    #    #    #
   #    #    #    #
   #     #    #  #
  #   #######   #
 # # # # # # ###
##   ########
 ####
)"
	);

int main()
{
	scene::Scene s;

	srand(time(nullptr));

	auto ms = SDL::MockupScreen::GetInstance();
	int i = 10;
	ms->Clear(Color::White);

	while (i-->0)
	{
		s.AddNode(
			utils::SharedPtr<DrawableNode>::Make(
				test,
				Vector2<int16_t>{int16_t(rand() % 128), int16_t(rand() % 64)},
				Color::Black
				)
			);
	}

	s.Draw(ms);
	ms->Render();

	std::this_thread::sleep_for(5s);
	return 0;
}
