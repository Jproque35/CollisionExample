#include "Engine.h"
#include "Collidable.h"
#include "Circle.h"

Engine::Engine() :
	m_CurrColIdx(0),
	m_CurrStage(EngineStage::START) {

	this->m_Window.create(VideoMode(640.0f, 480.0f), "Collision Example", Style::Default);

	for (int i = 0; i < maxObjects; ++i) {
		this->m_Collidables[i] = NULL;
	}
}

void Engine::addCollidable(Collidable& col) {
	try {
		this->m_Collidables[this->m_CurrColIdx++] = &col;
	}
	catch (exception& e) {

	}
}

void Engine::start() {
	Circle* newCircle = new Circle(Vector2f(320.0f, 240.0f), 50.0f);

	this->addCollidable(*newCircle);

	this->m_CurrStage = EngineStage::UPDATE;
}

void Engine::process() {
	Clock clock;

	while (this->m_Window.isOpen()) {
		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}

	this->m_CurrStage = EngineStage::EXIT;
}

void Engine::exit() {
	for (int i = 0; i < maxObjects; ++i) {
		if (this->m_Collidables[i] != NULL) {
			delete(this->m_Collidables[i]);
			this->m_Collidables[i] = NULL;
		}
	}

	this->m_CurrStage = EngineStage::CLOSE;
}

void Engine::run() {
	while (this->m_CurrStage != EngineStage::CLOSE) {
		if (this->m_CurrStage == EngineStage::START) {
			this->start();
		}
		else if (this->m_CurrStage == EngineStage::UPDATE) {
			this->process();
		}
		else if (this->m_CurrStage == EngineStage::EXIT) {
			this->exit();
		}
	}
}