/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#ifndef OOP_ARCADE_2018_IGRAPH_HPP
#define OOP_ARCADE_2018_IGRAPH_HPP

#include "Arcade.hpp"

namespace arcade {
	class IGraph {
	public:
		virtual ~IGraph() = default;

        virtual void deleteLib() = 0;

        virtual void initFrame() = 0;
        virtual void renderFrame() = 0;

        virtual std::string getName() const = 0;
        virtual void setAction(arcade::action *action) = 0;
        virtual void setEntity(const std::string &, const arcade::path_t &, const std::pair<float, float> &) = 0;
		virtual void setEntity(const std::string &, const std::string &, const std::pair<float, float> &) = 0;
		virtual void deleteEntity(const std::string &) = 0;
        virtual void updatePos(const std::string &, const std::pair<float, float> &) = 0;
		virtual void display(const std::string &) = 0;
	};
}

#endif //OOP_ARCADE_2018_IGRAPH_HPP
