#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Collidable;

class Controller {
private:
	int currIdx;
	float m_Speed;

	Controller(const Controller& other) = delete;
	Controller& operator=(const Controller& rhs) = delete;

public:
	Controller();
	~Controller();
	void update(float dtAsSeconds);
};

