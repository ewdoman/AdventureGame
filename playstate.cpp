#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"

PlayState PlayState::m_PlayState;

void PlayState::Init()
{
	//perform logic and init parameters before loading state
}

void PlayState::Cleanup()
{

}

//with the pointer to window theres no need to pass the game class

void PlayState::HandleEvents(GameEngine* game)
{
	sf::Event evt;
	//Loop through all window events
	while(game->window->pollEvent(evt))
	{
		if(evt.type == sf::Event::Closed){
			game->window->close();
		}
	}
}

void PlayState::Update(GameEngine* game)
{
	game->window->clear(sf::Color::Blue);
	game->window->display();
}

void PlayState::Draw(GameEngine* game)
{

}