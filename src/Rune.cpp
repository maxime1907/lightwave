//
// Created by longle-h on 22/01/17.
//

#include <iostream>
#include "../include/Rune.h"

Rune::Rune() {
    active = true;
    timeElapsed = 0;
}


Rune::~Rune() {}

bool Rune::isActive() {
    return this->active;
}

void Rune::run() {
    if (!active)
    {
        if (_clock.getElapsedTime().asSeconds() > 20.f) {
            active = true;
        }
    }
}

void Rune::desactivate() {
    _clock.restart();
    active = false;
}

bool Rune::checkCollision(sf::Sprite *sprite)
{
    if (sprite->getGlobalBounds().intersects(getGlobalBounds())) {
        if (active)
            return true;
        else
            return false;
    }
    return false;
}
