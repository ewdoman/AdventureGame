#include "gameengine.h"
#include "introstate.h"

#include <SFML/Graphics.hpp>

void Start()
{

	GameEngine game;

	game.Init();

	//set state to intro
	game.ChangeState(IntroState::Instance());

	//Main loop here
	game.MainLoop();

	//cleanup engine
	game.Cleanup();

	//deallocateWindow
	//game.DeallocateWindow(); 

}

int main()
{
	Start();
	return 0;
}
