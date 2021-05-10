#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bob {

private:
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;

	bool m_LeftPressed = false;
	bool m_RightPressed = false;
	float m_Speed;

public:
	Bob();
	Sprite getSprite();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(float elapsedTime);

};
