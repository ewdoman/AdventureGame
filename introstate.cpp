#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "gamestate.h"
#include "introstate.h"
#include "playstate.h"

IntroState IntroState::m_IntroState;

void IntroState::Init()
{
	//perform logic and init parameters before loading state
}

void IntroState::Cleanup()
{

}

// void IntroState::MainLoop()
// {
// 	// while ( window->isOpen() )
// 	// {
// 	// 	GameEngine::HandleEvents(); //process input/ handle events
// 	// 	//game.Update();
// 	// 	//game.Draw(); //renderframe
// 	// }
// }

//with the pointer to window theres no need to pass the game class

void IntroState::HandleEvents(GameEngine* game)
{
	sf::Event evt;
	//Loop through all window events
	while(game->window->pollEvent(evt))
	{
		if(evt.type == sf::Event::Closed){
			game->window->close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			game->ChangeState( PlayState::Instance() );
		}
	}
}

void IntroState::Update(GameEngine* game)
{
	game->window->clear(sf::Color::Black);
	game->window->display();
}

void IntroState::Draw(GameEngine* game)
{

}