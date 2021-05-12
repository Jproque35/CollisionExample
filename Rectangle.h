#pragma once
#include "Collidable.h"

class Circle;

class Rectangle :
    public Collidable {
private:
    Vector2f m_Dimensions;
    RectangleShape m_RectDrawable;

    Rectangle() = delete;
    Rectangle(const Rectangle& other) = delete;
    Rectangle& operator=(const Rectangle& rhs) = delete;

    bool intersectsRectangle(const Rectangle& col) const;
    bool intersectsCircle(const Circle& col) const;

public:
    Rectangle(const Vector2f& position, const Vector2f& dimensions);
    ~Rectangle();

    inline const Vector2f& getDimensions() const {
        return this->m_Dimensions;
    }

    inline float getLeft() const {
        return this->m_Position.x - this->m_Dimensions.x / 2;
    }

    inline float getTop() const {
        return this->m_Position.y - this->m_Dimensions.y / 2;
    }

    const Drawable& getDrawable() const;
    bool intersects(const Collidable& col) const;
    void update(float dtAsSeconds);
};

