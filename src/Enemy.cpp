//
// Created by longle-h on 21/01/17.
//

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include "Animation.h"
#include "Enemy.h"
#include "typedef.h"
#include "Player.h"

Enemy::Enemy(const std::string &player_sprite, int sizeX, int sizeY, int nbSprite, int nbSpriteLine, sf::Vector2f pos)
: ACharacter(player_sprite, sizeX, sizeY, nbSprite, nbSpriteLine)
{
    for (unsigned int i = 0; i < _nbSprite ; i++)
    	_vector[i].setPosition(pos);
    clock = new sf::Clock();
    _player = NULL;
    invicible = true;
}

Enemy::~Enemy()
{

}

Direction Enemy::getDirection()
{
    sf::FloatRect playerPos = _player->_vector[_player->_move].getGlobalBounds();
    sf::FloatRect pos = _vector[_move].getGlobalBounds();
    float difX;
    float difY;
    Direction dir;

    difY = (playerPos.top + playerPos.width / 2) - (pos.top + pos.width / 2);
    difX = (playerPos.left + playerPos.width / 2) - (pos.left + pos.width / 2);
    if (std::abs(difY) > std::abs(difX))
    {
        if ((difY + (pos.top + pos.width / 2)) < (pos.top + pos.width / 2))
            dir = UP;
        else
            dir = DOWN;
    } else {
        if ((difX + (pos.left + pos.width / 2)) < (pos.left + pos.width / 2))
            dir = LEFT;
        else
            dir = RIGHT;
    }
    return dir;
}

bool Enemy::checkCollision(Sprite *sprite)
{
    if (sprite->getGlobalBounds().intersects(_vector[_move].getGlobalBounds())) {
        return true;
    }
    return false;
}

bool Enemy::getInvicible()
{
    return invicible;
}

void Enemy::run()
{
    if (!invicible){
        _vector[_move].setColor(sf::Color(255, 50, 50, 255));
    } else
        _vector[_move].setColor(sf::Color(255, 255, 255, 255));
    if (clock->getElapsedTime().asSeconds() >= 5.f) {
        clock->restart();
        invicible = true;
    }
    if (invicible)
    {
        Direction dir = getDirection();
        if (dir == UP)
            move(0, -0.1, dir);
        else if (dir == DOWN)
            move(0, 0.1, dir);
        else if (dir == LEFT)
            move(-0.1, 0, dir);
        else
            move(0.1, 0, dir);
    }
}

void Enemy::setPlayer(Player *player)
{
    _player = player;
}

void Enemy::setInvicible(bool val)
{
    invicible = val;
}
