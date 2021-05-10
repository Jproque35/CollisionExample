#include "Bob.h";

Bob::Bob() {

	this->m_Speed = 400;
	this->m_Texture.loadFromFile("bob.png");
	this->m_Sprite.setTexture(this->m_Texture);

	this->m_Position.x = 500;
	this->m_Position.y = 800;

}

Sprite Bob::getSprite() {

	return this->m_Sprite;

}

void Bob::moveLeft() {

	this->m_LeftPressed = true;

}

void Bob::moveRight() {

	this->m_RightPressed = true;

}

void Bob::stopLeft() {

	this->m_LeftPressed = false;

}

void Bob::stopRight() {

	this->m_RightPressed = false;

}

void Bob::update(float elapsedTime) {

	if (this->m_RightPressed) {

		this->m_Position.x += this->m_Speed * elapsedTime;

	}

	if (this->m_LeftPressed) {

		this->m_Position.x -= this->m_Speed * elapsedTime;

	}

	this->m_Sprite.setPosition(this->m_Position);

}