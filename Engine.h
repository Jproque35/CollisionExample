#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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
class Controller;

class Engine {

private: 
	static Engine* instance;
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Bob m_Bob;
	EngineStage m_CurrStage;

	const static int maxObjects = 128;
	Collidable* m_Collidables[maxObjects];
	int m_NumColliders;
	Controller* m_Controller;

	Engine();
	~Engine();

	void input();
	void start();
	void process();
	void update(float dtAsSeconds);
	void draw();
	void exit();

public:
	inline static Engine* getInstance() {
		if (!instance) {
			instance = new Engine();
		}

		return instance;
	}

	inline static void resetInstance() {
		if (instance) {
			delete(instance);
		}

		instance = NULL;
	}

	inline int getNumCollidables() const {
		return this->m_NumColliders;
	}

	void addCollidable(Collidable& col);
	vector<Collidable*> getCollidableList() const;
	void run();

};

#endif