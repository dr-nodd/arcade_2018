/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Lib for SFML
*/

#include <iostream>
#include "SFMLLib.hpp"
#include "SFMLEntity.hpp"

arcade::SFML::SFML() : _window(sf::VideoMode::getDesktopMode(), "ARCADE", sf::Style::Fullscreen)
{
	setSound();
	initFrame();
	renderFrame();
}

arcade::SFML::~SFML() = default;

void arcade::SFML::deleteLib()
{
	_window.close();
	delete _music;
	for (const auto &it : _entities)
		delete it;
}

void arcade::SFML::initFrame()
{
	_window.clear(sf::Color::Black);
}

void arcade::SFML::renderFrame()
{
	_window.display();
}

std::string arcade::SFML::getName() const
{
	return ("lib_arcade_sfml.so");
}

void arcade::SFML::setAction(arcade::action *action)
{
	while (_window.pollEvent(_event)) {
		if (_event.type == sf::Event::Closed)
			*action = arcade::action::QUIT;
		if (_event.type == sf::Event::KeyPressed) {
			switch (_event.key.code) {
				case (sf::Keyboard::Up):
					*action = arcade::action::UP;
					break;
				case (sf::Keyboard::Down):
					*action = arcade::action::DOWN;
					break;
				case (sf::Keyboard::Left):
					*action = arcade::action::LEFT;
					break;
				case (sf::Keyboard::Right):
					*action = arcade::action::RIGHT;
					break;
				case (sf::Keyboard::P):
					*action = arcade::action::PAUSE;
					break;
				case (sf::Keyboard::Enter):
					*action = arcade::action::ENTER;
					break;
				case (sf::Keyboard::Space):
					*action = arcade::action::ACTION;
					break;
				case (sf::Keyboard::Escape):
					*action = arcade::action::QUIT;
					break;
				case (sf::Keyboard::W):
					*action = arcade::action::PREV_LIB;
					break;
				case (sf::Keyboard::C):
					*action = arcade::action::NEXT_LIB;
					break;
				case (sf::Keyboard::A):
					*action = arcade::action::PREV_GAME;
					break;
				case (sf::Keyboard::E):
					*action = arcade::action::NEXT_GAME;
					break;
				case (sf::Keyboard::Q):
					*action = arcade::action::BACK;
					break;
				case (sf::Keyboard::D):
					*action = arcade::action::RESTART;
					break;
				default:
					*action = arcade::action::UNDEFINED;
			}
		}
	}
}

void arcade::SFML::setEntity(const std::string &name, const arcade::path_t &path, const std::pair<float, float> &pos)
{
	for (const auto &it : _entities)
		if (name == it->getName())
			return;
	_entities.push_back(new SFMLEntity(name, path, pos));
}

void arcade::SFML::setEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos)
{
	for (const auto &it : _entities)
		if (name == it->getName()) {
			it->setText(text);
			return;
		}
	_entities.push_back(new SFMLEntity(name, text, pos));
}

void arcade::SFML::setSound()
{
	_music = new arcade::SFMLSound{};
	_music->setPath("./assets/menu/theme.ogg");
	_music->setMusic();
	_music->playMusic();
}

void arcade::SFML::deleteEntity(const std::string &name)
{
	for (unsigned long i = 0; i < _entities.size(); i++)
		if (name == _entities.at(i)->getName())
			_entities.erase(_entities.begin() + i);
}

void arcade::SFML::updatePos(const std::string &name, const std::pair<float, float> &pos)
{
	for (const auto &it : _entities)
		if (it->getName() == name)
			it->setPos(std::make_pair((pos.first * _window.getSize().x) / 100.0,
									  (pos.second * _window.getSize().y) / 100.0));
}

void arcade::SFML::display(const std::string &name)
{
	for (const auto &it : _entities)
		if (it->getName() == name) {
			if (it->getType() == "sprite")
				_window.draw(it->getSprite());
			else if (it->getType() == "text")
				_window.draw(it->getText());
		}
}

extern "C" arcade::IGraph *entryPoint()
{
	return new arcade::SFML;
}