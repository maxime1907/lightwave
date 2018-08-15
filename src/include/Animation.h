/*
** Animation.h for Animation in /home/klein-h/Documents/cpp_gameJam/include
** 
** Made by Arthur Klein
** Login   <klein_h>
** 
** Started on  Sat Jan 21 14:59:31 2017 Arthur Klein
** Last update Sat Jan 21 14:59:51 2017 Arthur Klein
*/

#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

class Animation
{
public:
    Animation(std::string nameFile, int sizeX, int sizeY, int nbSprite, int nbSpriteLine);
    virtual ~Animation();

public:

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

public:
    unsigned int _nbSprite;
    unsigned int _move;
    unsigned int _nbSpriteLine;
    sf::Clock _clock;
    std::vector<sf::Sprite> _vector;

};