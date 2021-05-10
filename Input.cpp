#include "Engine.h"

void Engine::input() {

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->m_Window.close();

	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {

		this->m_Bob.moveLeft();

	}
	else {

		this->m_Bob.stopLeft();

	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {

		this->m_Bob.moveRight();

	}
	else {

		this->m_Bob.stopRight();

	}

}