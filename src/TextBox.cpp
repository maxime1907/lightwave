//
// TextBox.cpp for Project-Master in /home/tekm/tek1/cpp_gameJam
// 
// Made by leroy_0
// Login   <leroy_0@epitech.eu>
// 
// Started on  Sat Jan 21 16:00:24 2017 leroy_0
// Last update Sat Jan 21 16:00:25 2017 leroy_0
//

#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include <string>
#include <iostream>

TextBox::TextBox(const std::string & filename, int size, float backgroundX, float backgroundY)
{
    sf::Font                *font = new sf::Font();
    font->loadFromFile(filename);

   	setFont(*font);
   	setString("TextBox");
    setCharacterSize(size);
    setStyle(sf::Text::Bold);
    setColor(sf::Color::White);
    setPosition(backgroundX, backgroundY);
}

TextBox::~TextBox()
{

}