#include "Engine.h"
#include "Collidable.h"

void Engine::draw() {

	this->m_Window.clear(Color::Black);

	//this->m_Window.draw(this->m_BackgroundSprite);
	//this->m_Window.draw(this->m_Bob.getSprite());

	for (int i = 0; i < maxObjects; ++i) {
		if (this->m_Collidables[i] != NULL) {
			this->m_Window.draw(this->m_Collidables[i]->getDrawable());
		}
	}

	this->m_Window.display();

}