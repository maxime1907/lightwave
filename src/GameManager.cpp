//
// GameManager.cpp for Project-Master in /home/tekm/tek1/cpp_gameJam
//
// Made by leroy_0
// Login   <leroy_0@epitech.eu>
//
// Started on  Sat Jan 21 21:49:28 2017 leroy_0
// Last update Sun Jan 22 00:09:41 2017 Sebastien Bruere
//

#include "Tile.h"
#include "Player.h"
#include "Animation.h"
#include "TextBox.h"
#include "Map.h"
#include "Collision.h"
#include "GameManager.h"
#include "Enemy.h"
#include "Spawner.h"
#include "Menu.h"
#include "Credits.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

GameManager::GameManager()
{
	this->screenX = 1280;
	this->screenY = 800;
    this->loop = 0;
	this->backgroundX = 1024;
	this->backgroundY = 1024;
	this->lvL = 0;
	this->nbSec = 20;
	this->initPosX_player = this->backgroundX / 2;
	this->initPosY_player = this->backgroundY / 2;
	this->isPlaying = false;
	this->_type_menu = MAIN;
	this->scoreNB = 0;

	this->credits = new Credits(screenX, screenY);
	this->menu = new Menu(screenX, screenY);
	this->map = new Env::Map("../src/maps/map01");
	this->window = new RenderWindow(VideoMode(screenX, screenY), "Developement build");
	this->clock = new Clock();
    this->clockLight = new Clock();
	this->event = new Event();
	this->player = new Player("../src/assets/player_move.png", initPosX_player, initPosY_player);
	Spawner::spawn(this->map->runes(), this->_runes);
	//_enemy->setPlayer(player);
    Spawner::spawn(map->espawn(), this->player, this->_enemy);
	this->background = new Tile(0, 0, backgroundX, backgroundY);
  	this->background->setTexture("../src/assets/MapDark.png", 0, 0, backgroundX, backgroundY);
  	this->score = new TextBox("../src/assets/Roboto-Regular.ttf", 10, initPosX_player - player->getView().getSize().x / 2 + 10, initPosY_player -  player->getView().getSize().y / 2 + 5);
	this->score->setString("Score : 0");
}

GameManager::~GameManager()
{

}

void GameManager::reset()
{
	delete map;
    this->clock->restart();
	this->map = new Env::Map("../src/maps/map01");
	delete player;
	this->player = new Player("../src/assets/player_move.png", initPosX_player, initPosY_player);
	_enemy.clear();
	Spawner::spawn(map->espawn(), this->player, this->_enemy);
}

void 		GameManager::manageEvents()
{
	if (this->clock->getElapsedTime().asSeconds() >= this->nbSec)
	{
        Spawner::spawn(map->espawn(), this->player, this->_enemy);
		if (this->nbSec > 2)
			this->nbSec -= 2;
		if (this->lvL < 42)
			this->lvL += 1;
        this->clock->restart();
	}
	while (window->pollEvent(*event))
    {
   		if (event->type == Event::Closed || (event->type == Event::KeyPressed && event->key.code == Keyboard::Escape))
	        isPlaying = false;
    }
}

void 		GameManager::manageDisplay(std::vector<Animation *> ligthTab)
{
	std::stringstream 		tmpscore;
    std::vector<sf::Sprite> lightRune;
    lightRune = this->map->getLightRune();
	window->setView(player->getView());
	score->setPosition(player->getView().getCenter().x - player->getView().getSize().x / 2 + 10, player->getView().getCenter().y -  player->getView().getSize().y / 2 + 5);

	window->clear();
	window->draw(*background);
	for (unsigned int i = 0; i < this->_enemy.size(); i++)
	{
		window->draw(this->_enemy[i]->_vector[_enemy[i]->_move]);
	}

	for (unsigned int i = 0; i < this->_runes.size(); i++)
	{
		window->draw(*(this->_runes[i]));
        if (this->_runes[i]->isActive())
            window->draw(lightRune[i], sf::BlendAdd);
	}
	window->draw(player->_vector[player->_move]);
	window->draw(player->_light);
    for (int i = 0; i < 8; i++)
    {
        window->draw((ligthTab[i]->_vector[loop]));
    }
	window->draw(player->getLifeBar());
    if (this->clockLight->getElapsedTime().asSeconds() > 0.1f)
    {
        this->clockLight->restart();
        loop++;
    }
    if (loop > 8)
    {
        loop = 0;
    }
	map->displayAll(*window);
	tmpscore << "Score : " << this->scoreNB;
	this->score->setString(tmpscore.str());
	tmpscore.str("");
	tmpscore.clear();
	window->draw(*score);
}

std::vector<Animation *> GameManager::setMyAnimation()
{
    int i = 0;
    std::vector<Animation *> ligthTab;
    for (int i = 0; i < 8; i++)
    {
        ligthTab.push_back(new Animation("../src/assets/flame.png", 9, 12, 9, 3));
    }
    for (int j = 0; j < 8 ;)
    {
        if (i == 9)
        {
            i = 0;
            j += 1;
        }
        switch (j)
        {
            case 0:
                ligthTab[j]->_vector[i].setPosition(155, 243);
                break;
            case 1:
                ligthTab[j]->_vector[i].setPosition(862, 243);
                break;
            case 2:
                ligthTab[j]->_vector[i].setPosition(862, 755);
                break;
            case 3:
                ligthTab[j]->_vector[i].setPosition(153, 755);
                break;
            case 4:
                ligthTab[j]->_vector[i].setPosition(325, 320);
                break;
            case 5:
                ligthTab[j]->_vector[i].setPosition(690,320);
                break;
            case 6:
                ligthTab[j]->_vector[i].setPosition(690,685);
                break;
            case 7:
                ligthTab[j]->_vector[i].setPosition(325, 685);
                break;
        }
        i++;
    }
    return (ligthTab);
}

void 		GameManager::manageCredits()
{
	while (window->pollEvent(*event))
	{
		if (event->type == Event::Closed || (event->type == Event::KeyPressed && event->key.code == Keyboard::Escape))
		{
			_type_menu = MAIN;
		}
	}

	window->draw(*credits);
}

void 		GameManager::manageMain()
{
	sf::SoundBuffer buffer;
	sf::Sound sound;
	buffer.loadFromFile("../src/assets/menu-switch.wav");
	sound.setBuffer(buffer);
	sound.setVolume(100);
	while (window->pollEvent(*event))
	{
		if (event->type == Event::Closed || (event->type == Event::KeyPressed && event->key.code == Keyboard::Escape))
		{
			window->close();
		}
		if (event->type == Event::KeyPressed && event->key.code == Keyboard::Return)
		{
			if (menu->cursor->getPosition().y == menu->_initY)
			{
				isPlaying = true;
				reset();
			}
			else if (menu->cursor->getPosition().y == menu->_initY + 114)
			{
				_type_menu = CREDITS;
			}
			else
				window->close();
		}
		if (event->type == Event::KeyPressed && event->key.code == Keyboard::Down)
		{
			sound.play();
			if (menu->cursor->getPosition().y == menu->_initY)
				menu->cursor->setPosition(menu->cursor->getPosition().x, menu->cursor->getPosition().y + 114);
			else if (menu->cursor->getPosition().y != menu->_initY && menu->cursor->getPosition().y == menu->_initY + 114)
				menu->cursor->setPosition(menu->cursor->getPosition().x, menu->cursor->getPosition().y + 114);
		}
		if (event->type == Event::KeyPressed && event->key.code == Keyboard::Up)
		{
			sound.play();
			if (menu->cursor->getPosition().y != menu->_initY)
				menu->cursor->setPosition(menu->cursor->getPosition().x, menu->cursor->getPosition().y - 114);
		}
	}

	window->setView(player->getView());
	window->draw(*menu);
	window->draw(*menu->cursor);
}

void 		GameManager::manageMenu()
{
	switch(_type_menu)
	{
		case MAIN:
			manageMain();
			break;
		case CREDITS:
			manageCredits();
			break;
	}
}

void 		GameManager::run()
{
	sf::Sound 					sound;
	sf::SoundBuffer 			buffer;
    std::vector<Animation *> 	ligthTab;
    ligthTab = setMyAnimation();

    buffer.loadFromFile("../src/assets/Ambiant_GGJ.ogg");
    sound.setBuffer(buffer);
	sound.setVolume(100);
	sound.setLoop(true);
	sound.play();

	while (window->isOpen())
    {
      	if (isPlaying){
      		manageEvents();

			player->manageInputs(*map, backgroundX, backgroundY);

			player->lightEffects();
			for (unsigned int i = 0; i < this->_enemy.size(); i++)
			{
				this->_enemy[i]->run();
				if (_enemy[i]->checkCollision(&(player->_vector[player->_move])) && player->_isAttack)
				{
					if (!_enemy[i]->getInvicible())
					{
						_enemy.erase(_enemy.begin() + i);
						this->scoreNB += 40 * (this->lvL + 1);
					}
				}
				else if (_enemy[i]->getInvicible() && _enemy[i]->checkCollision(&(player->_vector[player->_move])))
				{
					if (player->takeDamage(_enemy[i]->getDam()) == false)
						isPlaying = false;
				}
				if (_enemy[i])
				{
					if (player->getWave() && _enemy[i]->checkCollision(&(player->_light)))
						_enemy[i]->setInvicible(false);
				}
			}

			for (unsigned int i = 0; i < this->_runes.size(); i++)
			{
				this->_runes[i]->run();
				if (_runes[i]->checkCollision(&(player->_vector[player->_move])))
				{
					player->setWave(true);
					if (_runes[i]->isActive())
						_runes[i]->desactivate();
				}
			}

			manageDisplay(ligthTab);
		}
		else
		{
			window->clear();
			this->scoreNB = 0;
			player->getView().setCenter(screenX / 2, screenY / 2);
		    player->getView().setSize(screenX, screenY);
			manageMenu();
		}
		window->display();
    }
    sound.pause();
    sound.stop();
}
