/*
** GameManager.h for Project-Master in /home/tekm/tek1/cpp_gameJam
**
** Made by leroy_0
** Login   <leroy_0@epitech.eu>
**
** Started on  Sat Jan 21 21:49:40 2017 leroy_0
** Last update Sat Jan 21 21:49:40 2017 leroy_0
*/

#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "Map.h"
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "Animation.h"
#include "typedef.h"
#include "Menu.h"
#include "Rune.h"
#include "Credits.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GameManager
{
	public:
		GameManager();
		~GameManager();

		void 	run();
		void 	manageEvents();
		void 	manageDisplay(std::vector<Animation *> ligthTab);
		void 	manageMenu();
		void 	reset();

		void 	manageMain();
		void 	manageCredits();

		void 	loadSound(sf::SoundBuffer);


        std::vector<Animation *> setMyAnimation();
	private:
		bool 				isPlaying;
		Env::Map            *map;
		sf::RenderWindow 		*window;

		sf::Clock               *clock;
    sf::Clock               *clockLight;
	  	sf::Event               *event;

	  	Player              *player;
	  	Tile                *background;
	std::vector<Enemy*>   _enemy;
	std::vector<Rune*>   _runes;

		Menu 			*menu;

		Credits			*credits;

		TextBox 		*score;

	private:
		float         screenX;
		unsigned int  lvL;
		unsigned int  nbSec;
        unsigned int  loop;
		float         screenY;

		float         backgroundX;
		float         backgroundY;

		float         initPosX_player;
		float         initPosY_player;

		int 			scoreNB;

		type_menu		_type_menu;
};

#endif	/* __GAMEMANAGER_H_ */
