//
// Created by sadzeih on 20/01/17.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Tile.h"

Tile::Tile(int x, int y, int width, int height)
{
    _pos = new int[4];
    _pos[0] = x;
    _pos[1] = y;
    _pos[2] = x + width;
    _pos[3] = y + height;
    _width = width;
    _height = height;
    _quad = new sf::VertexArray(sf::Quads, 4);
    (*_quad)[0].position = sf::Vector2f(_pos[0], _pos[1]);
    (*_quad)[1].position = sf::Vector2f(_pos[2], _pos[1]);
    (*_quad)[2].position = sf::Vector2f(_pos[2], _pos[3]);
    (*_quad)[3].position = sf::Vector2f(_pos[0], _pos[3]);
}

Tile::~Tile()
{

}

void Tile::setTexture(const std::string& texture, int startX, int startY, int endX, int endY)
{
    if (!_texture.loadFromFile(texture))
        return;
    (*_quad)[0].texCoords = sf::Vector2f(startX, startY);
    (*_quad)[1].texCoords = sf::Vector2f(endX, startY);
    (*_quad)[2].texCoords = sf::Vector2f(endX, endY);
    (*_quad)[3].texCoords = sf::Vector2f(startX, endY);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &_texture;
    target.draw(*_quad, states);
}