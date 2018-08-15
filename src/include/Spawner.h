//
// Created by longle-h on 21/01/17.
//

#ifndef CPP_GAMEJAM_SPAWNER_H
#define CPP_GAMEJAM_SPAWNER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Rune.h"

class Spawner {
public:
    static std::vector<Enemy*> spawn(std::vector<sf::Sprite> posTab, Player * _player, std::vector<Enemy*> & v);
    static void spawn(std::vector<sf::Sprite> posTab, std::vector<Rune *> & v);
};

#endif //CPP_GAMEJAM_SPAWNER_H
