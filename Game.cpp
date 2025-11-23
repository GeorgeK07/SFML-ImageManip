/*
Game class function definitions
*/

// Include libraries
#include <SFML/Graphics.hpp>
// Include local header files
#include "ImgObject.h"
#include "Game.h"

// Create Game object with certain screen settings
Game::Game() {
  // Create 640x480 screen and scale 320x240 to it
  win = new sf::RenderWindow(sf::VideoMode({640, 480}), "SFML-ImageManip");
  sf::View view(sf::Vector2f(160, 120), sf::Vector2f(320, 240));
  win->setView(view);
  win->setPosition(
    sf::Vector2i(sf::VideoMode::getDesktopMode().size.x / 2 - 320,
    sf::VideoMode::getDesktopMode().size.y / 2 - 240));
  // Set framelimit to 60fps (Cannot be on at same time as vsync)
  win->setFramerateLimit(60);
  // win->setVerticalSyncEnabled(true); // Uncomment for vsync
  // Create ImgObject rect_obj
  rect_obj = new ImgObject();
}

// Game loop
void Game::gameLoop() {
  // While the window is open, check if window has been closed, then render game
  while (win->isOpen()) {
    //  While events are polled, check if window close event has occured, and
    // close window if so
    while (const std::optional event = win->pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        win->close();
      }
    }
    // Shift pixels in image and put image into texture
    rect_obj->shiftPixels();
    rect_obj->loadImgIntoTex();
    // Render Game
    renderGame();
  }
}

// Render Game
void Game::renderGame() {
  // Clear screen
  win->clear();
  // Draw image
  rect_obj->renderImgObject(win);
  // Display all objects drawn to screen
  win->display();
}

// Delete all Game related objects
Game::~Game() {
  // Delete char objects, char object array and window
  delete rect_obj;
  delete win;
}