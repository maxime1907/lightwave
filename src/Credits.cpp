//
// Credits.cpp for Project-Master in /home/tekm/tek1/cpp_gameJam
// 
// Made by leroy_0
// Login   <leroy_0@epitech.eu>
// 
// Started on  Sun Jan 22 03:57:07 2017 leroy_0
// Last update Sun Jan 22 03:57:07 2017 leroy_0
//

#include "Credits.h"
#include <string>
#include <iostream>

Credits::Credits(float backgroundX, float backgroundY)
{
	sf::Texture 	*credits_texture = new sf::Texture();

	_initX = backgroundX / 2 - 200;
	_initY = backgroundY / 2 + 151;

	credits_texture->loadFromFile("../src/assets/credits.jpg");
	setTexture(*credits_texture);
	setScale(backgroundX / credits_texture->getSize().x , backgroundY / credits_texture->getSize().y);
	setPosition(sf::Vector2f(0, 0));
}

Credits::~Credits()
{

}