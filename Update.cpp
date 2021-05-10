#include "Engine.h"
#include "Collidable.h"

void Engine::update(float dtAsSeconds) {

	for (int i = 0; i < maxObjects; ++i) {
		if (this->m_Collidables[i] != NULL) {
			this->m_Collidables[i]->update(dtAsSeconds);
		}
	}

}