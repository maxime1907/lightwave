//
// Created by longle-h on 21/01/17.
//

#ifndef CPP_GAMEJAM_COLLISION_H
#define CPP_GAMEJAM_COLLISION_H

#include "GameManager.h"
#include "Player.h"

namespace Env {
    class Collision {
    public:
        virtual ~Collision();
    public:
        static bool Collide(Player player, std::vector<sf::Sprite> sprites) {
            for (unsigned int i = 0; i < sprites.size(); ++i) {
                if (player._vector[player._move].getGlobalBounds().intersects(sprites[i].getGlobalBounds()))
                    return true;
            }
            return false;
        };
        static bool Collide(Player player, std::vector<sf::Sprite> sprites, int moveX, int moveY) {
            sf::Sprite tmp = player._vector[player._move];
            tmp.move((float)moveX, (float)moveY);
            for (unsigned int i = 0; i < sprites.size(); ++i) {
                if (tmp.getGlobalBounds().intersects(sprites[i].getGlobalBounds()))
                    return true;
            }
            return false;
        };
        static bool Collide(Player player, sf::Sprite sprites, int moveX, int moveY) {
                sf::Sprite tmp = player._vector[player._move];
                tmp.move((float)moveX, (float)moveY);
                if (tmp.getGlobalBounds().intersects(sprites.getGlobalBounds()))
                    return true;
            return false;
        };
        static bool Collide(Player player, sf::Sprite sprites) {
            if (player._vector[player._move].getGlobalBounds().intersects(sprites.getGlobalBounds()))
                return true;
            return false;
        };
    };
};

#endif //CPP_GAMEJAM_COLLISION_H
