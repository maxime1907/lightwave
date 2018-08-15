/*
** TextBox.h for Project-Master in /home/tekm/tek1/cpp_gameJam
** 
** Made by leroy_0
** Login   <leroy_0@epitech.eu>
** 
** Started on  Sat Jan 21 16:00:31 2017 leroy_0
** Last update Sat Jan 21 16:00:31 2017 leroy_0
*/

#ifndef __TEXTBOX_H_
#define __TEXTBOX_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class TextBox : public sf::Text
{
	public:
		TextBox(const std::string & name, int size, float backgroundX, float backgroundY);
		~TextBox();
};

#endif	/* __TEXTBOX_H_ */