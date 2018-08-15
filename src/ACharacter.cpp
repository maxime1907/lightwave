//
// Created by longle-h on 21/01/17.
//

#include "GameManager.h"
#include "ACharacter.h"

ACharacter::ACharacter(const std::string &player_sprite, int sizeX, int sizeY, int nbSprite,
                       int nbSpriteLine)
: Animation(player_sprite, sizeX, sizeY, nbSprite, nbSpriteLine)
{
    _dam = 5;
    _hp = 100;
}

unsigned int ACharacter::getDam() const {
    return this->_dam;
}

unsigned int ACharacter::getHP() const {
    return this->_hp;
}

unsigned int ACharacter::getSpeed() const {
    return this->_speed;
}

void ACharacter::setHP(unsigned int hp) {
    this->_hp = hp;
}

void ACharacter::move(float offsetX, float offsetY, Direction dir) {
    if (dir == LEFT)
    {
        moveLeft();
        sf::Transformable::move(offsetX, offsetY);
        for (unsigned int i = 0; i < _nbSprite ; i++)
            _vector[i].move(offsetX, offsetY);
    }

    if (dir == RIGHT)
    {
        moveRight();
        sf::Transformable::move(offsetX, offsetY);
        for (unsigned int i = 0; i < _nbSprite ; i++)
            _vector[i].move(offsetX, offsetY);
    }

    if (dir == UP)
    {
        moveUp();
        sf::Transformable::move(offsetX, offsetY);
        for (unsigned int i = 0; i < _nbSprite ; i++)
            _vector[i].move(offsetX, offsetY);
    }

    if (dir == DOWN) {
        moveDown();
        sf::Transformable::move(offsetX, offsetY);
        for (unsigned int i = 0; i < _nbSprite; i++)
            _vector[i].move(offsetX, offsetY);
    }
}

ACharacter::~ACharacter() {};
