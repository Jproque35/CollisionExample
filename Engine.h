#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bob.h"

using namespace sf;
using namespace std;

enum class EngineStage {
	START,
	UPDATE,
	EXIT,
	CLOSE
};

class Collidable;

class Engine {

private: 
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Bob m_Bob;
	EngineStage m_CurrStage;

	const static int maxObjects = 128;
	Collidable* m_Collidables[maxObjects];
	int m_CurrColIdx;

	void input();
	void start();
	void process();
	void update(float dtAsSeconds);
	void draw();
	void exit();

public:
	Engine();
	void addCollidable(Collidable& col);
	void run();

};