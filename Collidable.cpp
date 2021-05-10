#include "Collidable.h"
#include <iostream>

Collidable::Collidable(const Vector2f& position, CollidableType type) :
	m_Position(position),
	m_Type(type) {}

Collidable::~Collidable() {
	cout << "Collidable: Deleting Collidable..." << endl;
}