#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include "Collidable.h"

class Rectangle;

class Circle :
    public Collidable {
private:
    Circle() = delete;
    Circle(const Circle& other) = delete;
    Circle& operator=(const Circle& rhs) = delete;

    bool intersectsRectangle(const Rectangle& col) const;
    bool intersectsCircle(const Circle& col) const;

protected:
    float m_Radius;
    CircleShape m_CircleDrawable;

public:
    Circle(const Vector2f& position, float radius);
    ~Circle();

    float getRadius() const {
        return this->m_Radius;
    }

    const Drawable& getDrawable() const;
    bool intersects(const Collidable& col) const;
    void update(float dtAsSeconds);
};

#endif CIRCLE_H

