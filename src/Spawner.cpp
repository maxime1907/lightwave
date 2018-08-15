//
// Created by longle-h on 22/01/17.
//

#include "Enemy.h"
#include "Spawner.h"
#include <iostream>
#include <vector>

std::vector<Enemy*> Spawner::spawn(std::vector <sf::Sprite> posTab, Player * _player, std::vector<Enemy*> & v) {
    unsigned int i = 0;
    while (i < posTab.size()) {
        Enemy * _enemy = new Enemy("../src/assets/enemy.png", 36, 36, 16, 4, posTab[i].getPosition());
        _enemy->setPlayer(_player);
        v.push_back(_enemy);
        i++;
    }
    return v;
}


void Spawner::spawn(std::vector <sf::Sprite> posTab, std::vector<Rune *> &v) {
    unsigned int i = 0;
    while (i < posTab.size()) {
        Rune * _rune = new Rune();
        _rune->setPosition(posTab[i].getPosition());
        _rune->setTextureRect(posTab[i].getTextureRect());
        v.push_back(_rune);
        i++;
    }
}