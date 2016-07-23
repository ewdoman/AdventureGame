#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "gamestate.h"

void GameEngine::Init()
{

	int flags = 0;

	window = new sf::RenderWindow(sf::VideoMode(640, 480, 32), "Awakening");
	//sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Awakening");

	// enable vsync
	window->setVerticalSyncEnabled(true); // call it once, after creating the window

	// change the size of the window
	window->setSize(sf::Vector2u(640, 480));

	// change the title of the window
	window->setTitle("Awakening");

	// set frame rate limit
	window->setFramerateLimit(60); // call it once, after creating the window

	//set m_Running
	if(window->isOpen()){
		m_running = true;
	}

	//fullscreen
	// if(fullscreen) {

	// }

}

void GameEngine::Cleanup()
{
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
	//TODO: check if this deletes window early
	//deallocate window space
	delete window;
}

void GameEngine::ChangeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		//states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		//states.back()->Resume();
	}
}

void GameEngine::MainLoop()
{
	while ( window->isOpen() )
	{
		GameEngine::HandleEvents(); //process input/ handle events
		GameEngine::Update();
		//game.Draw(); //renderframe
	}
}

void GameEngine::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void GameEngine::DeallocateWindow() 
{
	//deallocate window space
	delete window;
}