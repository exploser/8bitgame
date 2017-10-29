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
	int i = 300;
	ms->Clear(Color::White);

	auto ship = utils::SharedPtr<DrawableNode>::Make(
		test,
		Vector2<int16_t>{-5, int16_t((rand() % 16) + 32)},
		Color::Black
		);

	s.AddNode(
		ship
		);

	while (i-->0)
	{
		ms->Clear(Color::White);

		auto curpos = ship->GetPosition();
		++curpos.x;
		ship->SetPosition(curpos);
		
		s.Draw(ms);

		ms->Render();
		std::this_thread::sleep_for(1000ms / 30);
	}

	return 0;
}
