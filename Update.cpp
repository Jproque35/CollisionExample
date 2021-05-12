#include "Engine.h"
#include "Collidable.h"
#include "Controller.h"

void Engine::update(float dtAsSeconds) {

	this->m_Controller->update(dtAsSeconds);

	for (int i = 0; i < maxObjects; ++i) {
		if (this->m_Collidables[i] != NULL) {
			this->m_Collidables[i]->update(dtAsSeconds);
		}
	}

}