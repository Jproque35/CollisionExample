#include "Controller.h"
#include "Collidable.h"
#include "Engine.h"

Controller::Controller() :
	currIdx(0),
	m_Speed(100.0f) {}

Controller::~Controller() {

}

void Controller::update(float dtAsSeconds) {

	vector<Collidable*> colList = Engine::getInstance()->getCollidableList();

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		++this->currIdx;
		this->currIdx = this->currIdx % colList.size();
	}

	if (colList.size() > 0) {
		float xPos = colList[this->currIdx]->getPosition().x;
		float yPos = colList[this->currIdx]->getPosition().y;

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			yPos -= this->m_Speed * dtAsSeconds;
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			xPos -= this->m_Speed * dtAsSeconds;
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			xPos += this->m_Speed * dtAsSeconds;
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			yPos += this->m_Speed * dtAsSeconds;
		}

		colList[this->currIdx]->setPosition(Vector2f(xPos, yPos));
	}
}
