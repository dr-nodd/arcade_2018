/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFMLSound
*/

#ifndef OOP_ARCADE_2018_SFMLSOUND_HPP
#define OOP_ARCADE_2018_SFMLSOUND_HPP

#include "ISound.hpp"
#include <SFML/Audio.hpp>

namespace arcade {
	class SFMLSound : public ISound {
	public:
		void setMusic() override;
		void playMusic() override;
		void stopMusic() override;
		void setPath(std::string);
		std::string getPath();

	private:
		std::string _path;
		sf::Music _music;
	};
}

#endif //OOP_ARCADE_2018_SFMLSOUND_HPP
