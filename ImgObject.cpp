/*
ImgObject class function definitions
*/

// Include libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <iostream>
// Include local header files
#include "ImgObject.h"

// Create img_obj and tex_obj objects
ImgObject::ImgObject() {
  // Set vars
  x_pos = 240;
  y_pos = 120;
  sine_pos = 0;
  sine_pos_adj = 0;
  // Load image into base_img_obj
  base_img_obj = new sf::Image;
  base_img_obj->loadFromFile("sonic1title.png");
  if (!base_img_obj->loadFromFile("sonic1title.png")) {
    std::cout << "Image failed to load.\n";
    exit(1);
  }
  // Load image into working_img_obj
  working_img_obj = new sf::Image;
  working_img_obj->loadFromFile("sonic1title.png");
  if (!working_img_obj->loadFromFile("sonic1title.png")) {
    std::cout << "Image failed to load.\n";
    exit(1);
  }
  // Create new text_obj and sprite_obj and set properties
  tex_obj = new sf::Texture;
  sprite_obj = new sf::Sprite;
}

// Shift pixels in image
void ImgObject::shiftPixels() {
  // Nested for loop that shifts every 2nd line in image
  //  Also create var to hold pixel data, reset sine_pos, and add an adjustment
  // to sine_pos
  sf::Color prev_pixel_color;
  sine_pos = 0;
  sine_pos = sine_pos + sine_pos_adj;
  for (int i = 0; i < base_img_obj->getSize().y; i++) {
    for (int j = 0; j < base_img_obj->getSize().x; j++) {
      prev_pixel_color = base_img_obj->getPixel(j, i);
      if (j + 8 * sin(sine_pos) < base_img_obj->getSize().x && j + 8 * sin(sine_pos) > 0) {
        working_img_obj->setPixel(j + 8 * sin(sine_pos), i, prev_pixel_color);
      }
    }
    // Add a certain amount to sine_pos each line
    sine_pos = sine_pos + 0.1;
  }
  // Add a certain amount to sine_pos_adj, basically changes speed
  sine_pos_adj = sine_pos_adj + 0.1;
}

// Load modified img_obj into tex_obj to prepare for rendering
void ImgObject::loadImgIntoTex() {
  tex_obj->loadFromImage(*working_img_obj);
  sprite_obj->setTexture(*tex_obj);
}

// Render sprite_obj of ImgObject
void ImgObject::renderImgObject(sf::RenderWindow* win) {
  win->draw(*sprite_obj);
}

// Set sine_pos
void ImgObject::setSinePos(double arg_sine_pos) { sine_pos = arg_sine_pos; }

// Get sine_pos
double ImgObject::getSinePos() { return sine_pos; }

// Delete all char_obj related objects
ImgObject::~ImgObject() {}