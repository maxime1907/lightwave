//
// Created by longle-h on 21/01/17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Map.h"


//Display Function
void Env::Map::displayAll(sf::RenderWindow & window) {

    unsigned int i = 0;
    while (i < _wall.size())
        window.draw(_wall[i++]);
    i = 0;
    while (i < _spikes.size())
        window.draw(_spikes[i++]);
    i = 0;
    while (i < _torchLights.size()) {
        if (this->_clockLight[i].getElapsedTime().asSeconds() > 0.1f && _torchLights[i].getScale() == sf::Vector2f(1.05, 1.05)) {
            _torchLights[i].setScale(sf::Vector2f(1, 1));
            this->_clockLight[i].restart();
        }
        else if (this->_clockLight[i].getElapsedTime().asSeconds() > 0.1f) {
            _torchLights[i].setScale(sf::Vector2f(1.05, 1.05));
            this->_clockLight[i].restart();
        }
        window.draw(_torchLights[i++], sf::BlendAdd);
    }
}

//Entity Creation
void Env::Map::create(std::string &asset, int startX, int startY, int lenX, int lenY, std::vector<sf::Sprite> & vector) {
    sf::Sprite sprite;
    if (asset.compare("0") != 0) {
        sf::Texture *texture = new sf::Texture;
        if (!texture->loadFromFile(asset))
            return;
        texture->setSmooth(true);
        sprite.setTexture((*texture));
    }

    sprite.setTextureRect(sf::IntRect(0, 0, lenX, lenY));

    sprite.setPosition(startX, startY);
    vector.push_back(sprite);
}
//Light Creation
void Env::Map::create(std::string &asset, int startX, int startY, std::vector<sf::Sprite> & vector) {
    sf::Sprite sprite;
    if (asset.compare("0") != 0) {
        sf::Texture *texture = new sf::Texture;
        if (!asset.empty() && !texture->loadFromFile(asset))
            return;
        texture->setSmooth(true);
        sprite.setTexture((*texture));
        sprite.setOrigin(330 / 2, 330/ 2);
    }

    //sprite.setTextureRect(sf::IntRect(0, 0, lenX, lenY));

    sprite.setPosition(startX, startY);
    vector.push_back(sprite);
}

void Env::Map::createEntity(std::string &type, std::string &asset, int startX, int startY, int lenX, int lenY) {
    if (type.compare("Wall") == 0) {
        this->create(asset, startX, startY, lenX, lenY, this->_wall);
    }
    else if (type.compare("Spike") == 0) {
        this->create(asset, startX, startY, lenX, lenY, this->_spikes);
    }
    else if (type.compare("LightRune") == 0) {
        this->create(asset, startX, startY, this->_runeLights);
    }
    else if (type.compare("LightTorch") == 0) {
        this->create(asset, startX, startY, this->_torchLights);
    }
    else if (type.compare("ESpawn") == 0){
        this->create(asset, startX, startY, lenX, lenY, this->_espawn);
    }
    else if (type.compare("Rune") == 0){
        this->create(asset, startX, startY, lenX, lenY, this->_runes);
    }
}


//CTOR/DTOR
Env::Map::Map(const std::string &mapFile) {
    std::ifstream file(mapFile.c_str());
    std::vector<std::string> toParse;
    std::stringstream  tmp;
    std::string        type("");
    std::string        asset("");
    int                startX = 0;
    int                startY = 0;
    int                lenX = 0;
    int                lenY = 0;
    int                _case = 0;

    for (std::string line; std::getline(file, line);)
        toParse.push_back(line);
    for (unsigned int i = 0; i < toParse.size() ; ++i) {
        tmp.str("");
        tmp.clear();
        tmp << toParse[i];
        _case = 0;
        asset = "";
        for (std::string elem; std::getline(tmp, elem, ',');) {
            switch (_case) {
                case 0:
                    type = elem;
                    break;
                case 1:
                    asset = elem;
                    break;
                case 2:
                    startX = std::atoi(elem.c_str());
                    break;
                case 3:
                    startY = std::atoi(elem.c_str());
                    break;
                case 4:
                    lenX = std::atoi(elem.c_str());
                    break;
                case 5:
                    lenY = std::atoi(elem.c_str());
                    break;
            }
            _case++;
        }
        this->createEntity(type, asset, startX, startY, lenX, lenY);
    }
    for (int j = 0; j < 8; ++j) {
        sf::Clock tmp;
        this->_clockLight.push_back(tmp);
    }
}

Env::Map::~Map() {}
