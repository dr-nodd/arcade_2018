/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Lib for SDL
*/

#ifndef OOP_ARCADE_2018_SDLLIB_HPP
#define OOP_ARCADE_2018_SDLLIB_HPP

#include <vector>
#include "IGraph.hpp"
#include "SDLEntity.hpp"

namespace arcade {
	class SDL : public IGraph {
	public:
		SDL();
		~SDL() override;

		void deleteLib() override;

		void initFrame() override;
		void renderFrame() override;

		std::string getName() const override;
		void setAction(arcade::action *) override;
		void setEntity(const std::string &, const arcade::path_t &, const std::pair<float, float> &) override;
		void setEntity(const std::string &, const std::string &, const std::pair<float, float> &) override;

		void deleteEntity(const std::string &) override;
		void updatePos(const std::string &, const std::pair<float, float> &) override;
		void display(const std::string &) override;

	private:
		SDL_Surface *_window;
		SDL_Event _event;
		std::vector<arcade::SDLEntity> _entities;
	};
}

#endif //OOP_ARCADE_2018_SDLIB_HPP
