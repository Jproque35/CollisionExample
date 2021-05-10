#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class CollidableType {
	UNKNOWN,
	RECTANGLE,
	CIRCLE,
	POINT
};

class Collidable {
private:
	Collidable() = delete;
	Collidable(const Collidable& other) = delete;
	Collidable& operator=(const Collidable& rhs) = delete;

protected:
	Vector2f m_Position;
	CollidableType m_Type;
	bool m_Colliding = false;

public:
	Collidable(const Vector2f& position, CollidableType type);
	virtual ~Collidable();

	inline const Vector2f& getPosition() const {
		return this->m_Position;
	}

	inline void setPosition(const Vector2f& position) {
		this->m_Position = position;
	}

	inline const CollidableType getType() const {
		return this->m_Type;
	}

	virtual const Drawable& getDrawable() const = 0;
	virtual bool intersects(const Collidable& col) = 0;
	virtual void update(float dtAsSeconds) = 0;
};

#endif

