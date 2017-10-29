#include "SDLScreen.hpp"

#include "Sprites.hpp"

#include <string>
#include <sstream>
#include <thread>

using namespace std::literals;
using namespace engine;

static auto test = sprite::FromAscii(
	R"(
 ####
#    ################
 # # # # # # # # # # ###
  #    ###############   ##
   #          #      #    #
    #        #        #    #
   #          #      #    #
  #   ###############   ##
 # # # # # # # # # # ###
#    ################
 #### 
)"
	);

int main()
{
	srand(time(nullptr));

	auto ms = SDL::MockupScreen::GetInstance();
	int64_t i = 10;
	ms->Clear(1);

	while (i-->0)
	{
		ms->Draw(*test, rand() % 128, rand() % 64, 0);
	}

	ms->Render();
	std::this_thread::sleep_for(5s);
	return 0;
}
