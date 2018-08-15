//
// Created by longle-h on 21/01/17.
//

#ifndef CPP_GAMEJAM_ENEMY_H
#define CPP_GAMEJAM_ENEMY_H

#include <string>
#include "ACharacter.h"
#include "Player.h"

class Enemy : public ACharacter {
private:
    Player *_player;
    Clock *clock;
    bool invicible;
public:
    Enemy(const std::string & player_sprite,int sizeX, int sizeY, int nbSprite, int nbSpriteLine, sf::Vector2f pos);
    virtual ~Enemy();

    void setPlayer(Player *player);

    Direction getDirection();

    bool checkCollision(Sprite *sprite);
    void setInvicible(bool val);
    bool getInvicible();

    void run();
};

#endif //CPP_GAMEJAM_ENEMY_H
