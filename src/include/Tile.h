//
// Created by sadzeih on 20/01/17.
//

#ifndef CPP_GAMEJAM_TILE_H
#define CPP_GAMEJAM_TILE_H

#include <SFML/Graphics.hpp>
#include <string>

class Tile: public sf::Drawable, public sf::Transformable
{
protected:
    int* _pos;
    int _width;
    int _height;
    sf::VertexArray* _quad;
    sf::Texture _texture;
public:
    Tile(int x, int y, int width, int height);
    ~Tile();

    void setTexture(const std::string& texture, int startX, int startY, int endX, int endY);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //CPP_GAMEJAM_TILE_H
