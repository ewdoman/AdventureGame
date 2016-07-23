#include "Game.h"

void Game::Start(void)
{
  if(_gameState != Uninitialized)
    return;

  _mainWindow.create(sf::VideoMode(640,480,32),"Awakening");
  _gameState = Game::Playing;
  
  while(!IsExiting())
  {
    MainLoop();
  }

  _mainWindow.close();
}

bool Game::IsExiting()
{
  if(_gameState == Game::Exiting) 
    return true;
  else 
    return false;
}

void Game::MainLoop()
{
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {
        switch(_gameState)
        {
          case Game::Playing:
          {
              _mainWindow.clear(sf::Color(0,0,0));
              _mainWindow.display();
            
              if(currentEvent.type == sf::Event::Closed)
              {
                  _gameState = Game::Exiting;
              }
              break;
          }
        }
    }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
