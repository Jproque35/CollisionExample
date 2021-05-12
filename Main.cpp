// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"

using namespace sf;

int main()
{
	Engine* e = Engine::getInstance();

	e->run();

	Engine::resetInstance();

	return 0;

}