#include "Rectangle.h"
#include "Circle.h"
#include "Engine.h"

Rectangle::Rectangle(const Vector2f& position, const Vector2f& dimensions) :
	Collidable(position, CollidableType::RECTANGLE),
	m_Dimensions(dimensions),
	m_RectDrawable(dimensions) {
	this->m_RectDrawable.setFillColor(Color::White);
}

Rectangle::~Rectangle() {
	cout << "Rectangle: Destroying Rectangle..." << endl;
}

bool Rectangle::intersectsCircle(const Circle& col) const {
	return col.intersects(*this);
}

bool Rectangle::intersectsRectangle(const Rectangle& col) const {
	bool xIntersection = this->getLeft() < col.getLeft() + col.m_Dimensions.x
						&& col.getLeft() < this->getLeft() + this->m_Dimensions.x;
	bool yIntersection = this->getTop() < col.getTop() + col.m_Dimensions.y
						&& col.getTop() < this->getTop() + this->m_Dimensions.y;

	return yIntersection && xIntersection;
}

bool Rectangle::intersects(const Collidable& col) const {

	if (col.getType() == CollidableType::CIRCLE) {
		return this->intersectsCircle(dynamic_cast<const Circle&>(col));
	}
	else if (col.getType() == CollidableType::RECTANGLE) {
		return this->intersectsRectangle(dynamic_cast<const Rectangle&>(col));
	}

	return false;
}

const Drawable& Rectangle::getDrawable() const {
	return this->m_RectDrawable;
}

void Rectangle::update(float dtAsSeconds) {
	this->m_RectDrawable.setFillColor(Color::White);

	vector<Collidable*> colList = Engine::getInstance()->getCollidableList();
	for (int i = 0; i < colList.size(); ++i) {
		if (colList[i] != this && this->intersects(*colList[i])) {
			this->m_RectDrawable.setFillColor(Color::Green);
		}
	}


	this->m_RectDrawable.setPosition(Vector2f(this->m_Position.x - this->m_Dimensions.x / 2, this->m_Position.y - this->m_Dimensions.y / 2));
}