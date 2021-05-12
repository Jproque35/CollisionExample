#include "Engine.h"
#include "Collidable.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Controller.h"

Engine* Engine::instance = NULL;

Engine::Engine() :
	m_NumColliders(0),
	m_CurrStage(EngineStage::START) {

	this->m_Window.create(VideoMode(640.0f, 480.0f), "Collision Example", Style::Default);

	for (int i = 0; i < maxObjects; ++i) {
		this->m_Collidables[i] = NULL;
	}
}

Engine::~Engine() {
	for (int i = 0; i < maxObjects; ++i) {
		if (this->m_Collidables[i] != NULL) {
			delete(this->m_Collidables[i]);
			this->m_Collidables[i] = NULL;
		}
	}

	delete(this->m_Controller);
	this->m_Controller = NULL;
}

void Engine::addCollidable(Collidable& col) {
	try {
		this->m_Collidables[this->m_NumColliders++] = &col;
	}
	catch (exception& e) {

	}
}

vector<Collidable*> Engine::getCollidableList() const {
	vector<Collidable*> desire;

	for (int i = 0; i < this->m_NumColliders; ++i) {
		desire.push_back(this->m_Collidables[i]);
	}

	return desire;
}

void Engine::start() {
	Circle* circle0 = new Circle(Vector2f(320.0f, 240.0f), 50.0f);
	Circle* circle1 = new Circle(Vector2f(100.0f, 100.0f), 50.0f);
	Rectangle* rectangle0 = new Rectangle(Vector2f(100.0f, 100.0f), Vector2f(80.0f, 60.0f));
	Rectangle* rectangle1 = new Rectangle(Vector2f(200.0f, 300.0f), Vector2f(100.0f, 50.0f));

	this->addCollidable(*circle0);
	this->addCollidable(*circle1);
	this->addCollidable(*rectangle0);
	this->addCollidable(*rectangle1);

	this->m_Controller = new Controller();

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