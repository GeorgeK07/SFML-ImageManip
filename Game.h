/*
Game class function signatures
*/

#ifndef GAME_H
#define GAME_H

// Include libraries
#include <SFML/Graphics.hpp>
// Include local header files
#include "ImgObject.h"

// Game class
class Game {
  private:
    sf::RenderWindow* win;
    ImgObject* rect_obj;
    std::string msg;
    int msg_size;
  public:
    // Create Game object with certain screen settings
    Game();
    // Game loop
    void gameLoop();
    // Render Game
    void renderGame();
    // Delete all Game related objects
    ~Game();
};

#endif