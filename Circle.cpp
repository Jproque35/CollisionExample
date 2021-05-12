#include "Circle.h"
#include "Rectangle.h"
#include "Engine.h"

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

bool Circle::intersectsRectangle(const Rectangle& col) const {
	float xPos = this->m_Position.x, yPos = this->m_Position.y;
	if (this->m_Position.x < col.getLeft()) {
		xPos = col.getLeft();
	}
	else if (this->m_Position.x > col.getLeft() + col.getDimensions().x) {
		xPos = col.getLeft() + col.getDimensions().x;
	}

	if (this->m_Position.y < col.getTop()) {
		yPos = col.getTop();
	}
	else if (this->m_Position.y > col.getTop() + col.getDimensions().y) {
		yPos = col.getTop() + col.getDimensions().y;
	}

	float xDist = this->m_Position.x - xPos;
	float yDist = this->m_Position.y - yPos;
	float dist = sqrt(xDist * xDist + yDist * yDist);

	return dist < this->m_Radius;
}

bool Circle::intersectsCircle(const Circle& col) const {
	float xDiff = abs(this->m_Position.x - col.m_Position.x);
	float yDiff = abs(this->m_Position.y - col.m_Position.y);
	float dist = sqrt(xDiff * xDiff + yDiff * yDiff);

	return this->m_Radius + col.m_Radius > dist;
}

bool Circle::intersects(const Collidable& col) const {
	if (col.getType() == CollidableType::CIRCLE) {
		return this->intersectsCircle(dynamic_cast<const Circle&>(col));
	}
	else if (col.getType() == CollidableType::RECTANGLE) {
		return this->intersectsRectangle(dynamic_cast<const Rectangle&>(col));
	}

	return false;
}

void Circle::update(float dtAsSeconds) {
	this->m_CircleDrawable.setFillColor(Color::White);

	vector<Collidable*> colList = Engine::getInstance()->getCollidableList();
	for (int i = 0; i < colList.size(); ++i) {
		if (colList[i] != this && this->intersects(*colList[i])) {
			this->m_CircleDrawable.setFillColor(Color::Green);
		}
	}

	this->m_CircleDrawable.setPosition( Vector2f(this->m_Position.x - this->m_Radius, this->m_Position.y - this->m_Radius) );
}