#include "Circle.h"

Circle::Circle(const Vector2f& position, float radius) :
	Collidable(position, CollidableType::CIRCLE),
	m_Radius(radius),
	m_CircleDrawable(this->m_Radius) {

	this->m_CircleDrawable.setFillColor(Color::White);

}

Circle::~Circle() {
	cout << "Circle: Deleting Circle..." << endl;
}

const Drawable& Circle::getDrawable() const {
	return this->m_CircleDrawable;
}

bool Circle::intersectsCircle(const Circle& col) {

	float xDiff = abs(this->m_Position.x - col.m_Position.x);
	float yDiff = abs(this->m_Position.y - col.m_Position.y);
	float dist = sqrt(xDiff * xDiff + yDiff * yDiff);

	if (this->m_Radius + col.m_Radius > dist) {
		this->m_Colliding = true;
		return true;
	}
	else {
		return false;
	}
}

bool Circle::intersects(const Collidable& col) {

	if (col.getType() == CollidableType::CIRCLE) {
		return this->intersectsCircle(dynamic_cast<const Circle&>(col));
	}

	return false;
}

void Circle::update(float dtAsSeconds) {
	this->m_CircleDrawable.setPosition( Vector2f(this->m_Position.x - this->m_Radius, this->m_Position.y - this->m_Radius) );
}