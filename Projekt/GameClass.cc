#include "GameClass.h"

//GAME

void Game::initializeVariables() {
    this->window = nullptr;

    //Logika
}

//tworzy okno

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,800), "Game");
    this->window->setFramerateLimit(60);
}

void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &this->states));
}

//konstruktor

Game::Game() {
    this->initializeVariables();
    this->initWindow();
    this->initStates();
}

//dektruktor

Game::~Game() {
    delete this->window;

    while(!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}
//akcesory

//zwraca czy okno jest otwarte

const bool Game::windowIsOpen() const {
    return this->window->isOpen();
}

//funkcje

//zamyka okno


void Game::updateEvents() {
    while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();
        }
}

void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::update() {
    this->updateEvents();
    if(!this->states.empty()) {
        this->states.top()->update();

        if(this->states.top()->getQuit()) {

            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }

    }
    else 
        this->window->close();
}


void Game::render() {
    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render();
    
    this->window->display();
}

//uruchamia gre

void Game::run() {
    while (this->window->isOpen()) {
            
            this->updateDt();

            this->update();

            this->render();
    }
}