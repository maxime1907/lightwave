//
// Life.cpp for Project-Master in /home/tekm/tek1/cpp_gameJam
// 
// Made by leroy_0
// Login   <leroy_0@epitech.eu>
// 
// Started on  Sun Jan 22 01:32:18 2017 leroy_0
// Last update Sun Jan 22 01:32:19 2017 leroy_0
//

#include "Life.h"

Life::Life(const sf::Vector2f & position)
{
	sf::Texture 	*life_bar_texture = new sf::Texture();

	_life = 100;
	
	_life_bar = new sf::Sprite();
	_life_bar->setPosition(position);

	life_bar_texture->loadFromFile("../src/assets/bar_de_vie.jpg");
	_life_bar->setTexture(*life_bar_texture);
}

Life::~Life()
{

}

float 			Life::getLife() const
{
	return (_life);
}

void 			Life::setLife(float life)
{
	_life = life;
	if (_life < 0)
		_life = 0;
	if (_life > 100)
		_life = 100;
	manageLife();
}
	
void 			Life::manageLife()
{
	_life_bar->setScale(_life / 100, 1);
}

sf::Sprite 		Life::getLifeBar()
{
	return (*_life_bar);
}

void 			Life::setLifePosition(const sf::Vector2f position)
{
	_life_bar->setPosition(position);
}