/*
ImgObject class function signatures
*/

#ifndef IMGOBJECT_H
#define IMGOBJECT_H

// Include libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

// ImgObject class
class ImgObject {
  private:
    sf::Image* base_img_obj;
    sf::Image* working_img_obj;
    sf::Texture* tex_obj;
    sf::Sprite* sprite_obj;
    int x_pos;
    int y_pos;
    double sine_pos;
  public:
    // Create img_obj and tex_obj objects
    ImgObject();
    // Shift pixels in image
    void shiftPixels();
    // Load modified img_obj into tex_obj to prepare for rendering
    void loadImgIntoTex();
    // Render sprite_obj of ImgObject
    void renderImgObject(sf::RenderWindow* win);
    // Set sine_pos
    void setSinePos(double arg_sine_pos);
    // Get sine_pos
    double getSinePos();
    // Delete all char_obj related objects
    ~ImgObject();
};

#endif