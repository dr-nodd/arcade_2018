/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFMLSound
*/

#include "SFMLSound.hpp"

void arcade::SFMLSound::setMusic()
{
	if (!_music.openFromFile(_path))
		throw (std::runtime_error("Couldn't load music"));
	_music.setLoop(true);
}

void arcade::SFMLSound::playMusic()
{
	_music.play();
}

void arcade::SFMLSound::stopMusic()
{
	_music.stop();
}

void arcade::SFMLSound::setPath(std::string path)
{
	_path = path;
}

std::string arcade::SFMLSound::getPath()
{
	return (_path);
}