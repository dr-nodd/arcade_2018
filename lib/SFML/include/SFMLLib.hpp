/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Lib for SFML
*/

#ifndef OOP_ARCADE_2018_SFMLLIB_HPP
#define OOP_ARCADE_2018_SFMLLIB_HPP

#include <SFML/Graphics.hpp>
#include "IGraph.hpp"
#include "SFMLSound.hpp"
#include "SFMLEntity.hpp"

namespace arcade {
	class SFML : public IGraph {
	public:
		SFML();
		~SFML() override;

		void deleteLib() override;

		void initFrame() override;
		void renderFrame() override;

		std::string getName() const override;
		void setAction(arcade::action *) override;
		void setEntity(const std::string &, const path_t &, const std::pair<float, float> &) override;
		void setEntity(const std::string &, const std::string &, const std::pair<float, float> &) override;
		void setSound();

		void deleteEntity(const std::string &) override;
		void updatePos(const std::string &, const std::pair<float, float> &) override;
		void display(const std::string &) override;

	private:
		sf::RenderWindow _window;
		sf::Event _event;
		std::vector<arcade::SFMLEntity *> _entities;
		arcade::SFMLSound *_music;
	};
}

#endif //OOP_ARCADE_2018_SFMLLIB_HPP
