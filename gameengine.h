#pragma once

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;

//class prototype for gamsestate, defined later
class GameState;

class GameEngine
{

    public:

      //replace with constructor/destructor
      void Init();
      void Cleanup();
      void DeallocateWindow();

      void ChangeState(GameState* state);
      void PushState(GameState* state);
      void PopState();

      void MainLoop();
      void HandleEvents();
      void Update();

      bool Running() { return m_running; }
      void setRunning(bool b) { m_running = b; }

      //make into a singleton
      sf::RenderWindow* window;

    private:
      //stack of states
      vector<GameState*> states;
      bool m_running;
      bool m_fullscreen;
};

#endif