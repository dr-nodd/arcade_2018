/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#ifndef OOP_ARCADE_2018_CACALIB_HPP
#define OOP_ARCADE_2018_CACALIB_HPP

#include <caca++.h>
#include "CacaEntity.hpp"
#include "IGraph.hpp"

namespace arcade {
	class Caca : public IGraph {
		public:
			Caca();
			~Caca() override;

			void deleteLib() override;

			void initFrame() override;
			void renderFrame() override;

			std::string getName() const override;
			void setAction(arcade::action *) override;
			void setEntity(const std::string &, const path_t &, const std::pair<float, float> &) override;
			void setEntity(const std::string &, const std::string &, const std::pair<float, float> &) override;

			void deleteEntity(const std::string &) override;
			void updatePos(const std::string &, const std::pair<float, float> &) override;
			void display(const std::string &) override;

		private:
			caca_canvas_t *_canvas;
			caca_display_t *_display;
			caca_event_t _event;
			int _evt;
			unsigned int const _event_mask;
			std::vector<arcade::CacaEntity> _entities;
	};
}

#endif //OOP_ARCADE_2018_CACALIB_HPP
