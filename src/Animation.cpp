//
// Animation.cpp for animation in /home/klein-h/Documents/cpp_gameJam/src
// 
// Made by Arthur Klein
// Login   <klein_h>
// 
// Started on  Sat Jan 21 14:58:29 2017 Arthur Klein
// Last update Sat Jan 21 14:58:32 2017 Arthur Klein
//

#include "Animation.h"

Animation::Animation(std::string nameFile, int sizeX, int sizeY, int nbSprite, int nbSpriteLine)
{
    unsigned int x = 0;
    unsigned int y = 0;

    _move = 0;

    sf::Texture *texture = new sf::Texture();

    texture->loadFromFile(nameFile);
    _nbSprite = nbSprite;
    _nbSpriteLine = nbSpriteLine;
    for (int j = 0; j < nbSprite; j++)
    {
        if (x + sizeX > texture->getSize().x)
        {
            x = 0;
            y += sizeY;
        }
        sf::IntRect rectSourceSprite(x, y, sizeX, sizeY);
        _vector.push_back(sf::Sprite(*texture,rectSourceSprite));
        x += sizeX;
    }
}

void Animation::moveLeft()
{
    if (_move < _nbSpriteLine * 2 || _move >= _nbSpriteLine * 3 - 1)
        _move = _nbSpriteLine * 2;
    if (_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        _clock.restart();
        _move++;
    }
}

void Animation::moveRight()
{
    if (_move < _nbSpriteLine  || _move >= (_nbSpriteLine * 2) - 1)
        _move = _nbSpriteLine;
    if (_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        _clock.restart();
        _move++;
    }
}

void Animation::moveUp()
{
    if (_move < _nbSpriteLine * 3 || _move >= _nbSpriteLine * _nbSpriteLine - 1)
        _move = _nbSpriteLine * 3;
    if (_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        _clock.restart();
        _move++;
    }
}

void Animation::moveDown()
{
    if (_move >= _nbSpriteLine - 1)
        _move = 0;
    if (_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        _clock.restart();
        _move++;
    }
}

Animation::~Animation()
{

}