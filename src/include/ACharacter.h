//
// Created by longle-h on 21/01/17.
//

#ifndef CPP_GAMEJAM_ICHARACTER_H
#define CPP_GAMEJAM_ICHARACTER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "typedef.h"

class ACharacter : public Animation, public sf::Sprite
{
protected:
    unsigned int     _hp;
    unsigned int     _dam;
    unsigned int     _speed;

public:
    ACharacter(const std::string & player_sprite, int sizeX, int sizeY, int nbSprite, int nbSpriteLine);
    virtual ~ACharacter();

    virtual void move(float offsetX, float offsetY, Direction dir);
public:
    unsigned int getHP() const;
    unsigned int getDam() const;
    unsigned int getSpeed() const;

public:
    void        setHP(unsigned int hp);
};

#endif //CPP_GAMEJAM_ICHARACTER_H
