//
// Created by longle-h on 21/01/17.
//


#ifndef CPP_GAMEJAM_MAP_HPP
#define CPP_GAMEJAM_MAP_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

namespace Env {
    class Map {

    protected:
        std::vector<sf::Sprite> _wall;
        std::vector<sf::Sprite> _spikes;
        std::vector<sf::Sprite> _runeLights;
        std::vector<sf::Sprite> _torchLights;
        std::vector<sf::Sprite> _runes;

        //Ennemy Spawn
        std::vector<sf::Sprite> _espawn;



    public:
        Map(const std::string &mapFile);
        ~Map();

    public:
        void    displayAll(sf::RenderWindow & window);


    public:
        std::vector<sf::Sprite> wall() const { return this->_wall;};
        std::vector<sf::Sprite> spikes() const { return this->_spikes;};
        std::vector<sf::Sprite> espawn() const { return this->_espawn;};
        std::vector<sf::Sprite> runes() const {return this->_runes;};
        std::vector<sf::Sprite> getLightRune() const {return this->_runeLights;};
        std::vector<sf::Clock>   _clockLight;

    private:
        void    createEntity(std::string & type, std::string & asset, int startX, int startY, int lenX, int lenY);
        void    create(std::string & asset, int startX, int startY, int lenX, int lenY, std::vector<sf::Sprite> & );
        void    create(std::string & asset, int startX, int startY, std::vector<sf::Sprite> & );


    };
};

#endif //CPP_GAMEJAM_MAP_HPP
