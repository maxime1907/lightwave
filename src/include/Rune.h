//
// Created by longle-h on 22/01/17.
//

#ifndef CPP_GAMEJAM_RUNE_H
#define CPP_GAMEJAM_RUNE_H

#include <SFML/Graphics.hpp>

class Rune : public sf::Sprite {
private:
    sf::Clock   _clock;
//    sf::Sprite  _sprite;
    int  timeElapsed;
    bool active;

public:
    Rune();
    ~Rune();

    void run();
    bool isActive();
    void desactivate();
    bool checkCollision(sf::Sprite *Sprite);
};

#endif //CPP_GAMEJAM_RUNE_H
