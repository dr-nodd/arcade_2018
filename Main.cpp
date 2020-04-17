/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Main
*/

#include <cstring>
#include <exception>
#include <iostream>
#include <unistd.h>
#include "Core.hpp"

void usage()
{
	std::cout << std::endl;
	std::cout << "USAGE: ./arcade ./lib_arcade_$libraryname.so" << std::endl;
	std::cout << std::endl;
	std::cout << "ARCADE, EPITECH 2019. Project by Arnaud LECLERCQ, Hugo BOULEUX, Nathalie HUGOT-POREZ" << std::endl;
	std::cout << std::endl;
	std::cout << "Keys:" << std::endl;
	std::cout << "Arrow up:\tMove up" << std::endl;
	std::cout << "Arrow down:\tMove down" << std::endl;
	std::cout << "Arrow left:\tMove left" << std::endl;
	std::cout << "Arrow right:\tMove right" << std::endl;
	std::cout << "Space:\t\tAction" << std::endl;
	std::cout << "Enter:\t\tSelect" << std::endl;
	std::cout << "P:\t\tPause the game" << std::endl;
	std::cout << "D:\t\tRestart the game" << std::endl;
	std::cout << "Q:\t\tBack to menu" << std::endl;
	std::cout << "W:\t\tChange to the previous lib" << std::endl;
	std::cout << "C:\t\tChange to the next lib" << std::endl;
	std::cout << "A:\t\tChange to the previous game" << std::endl;
	std::cout << "E:\t\tChange to the next game" << std::endl;
	std::cout << "Escape:\t\tQuit arcade" << std::endl;
	std::cout << std::endl;
}

int main(int ac, char *av[])
{
	try {
		if (ac != 2)
			throw (std::invalid_argument(
					"USAGE:\t./arcade ./lib_arcade_$libraryname.so\n\t./arcade -h | --help"));
		if (std::strcmp(av[1], "-h") == 0 || std::strcmp(av[1], "--help") == 0) {
			usage();
			return (0);
		}
		arcade::Core core(av[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return (84);
	}
	return (0);
}