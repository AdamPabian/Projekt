#include "GameClass.h"
        // funkcja prywatna
        void Game::initializeVariables() {
            this->window = nullptr;
        }
        // funkcja prywatna
        void Game::initializeWindow() {
            this->window = new sf::RenderWindow(sf::VideoMode(800,600),"My Game");
        }
        // akcesor
        const bool Game::windowOpen() const{
            return this->window->isOpen();
        }
        // funkcja
        void Game::updateEvents() {
            while (this->window->pollEvent(this->event)) {
                if(this->event.type == sf::Event::Closed)
                    this->window->close();
                if(this->event.type == sf::Event::KeyPressed) {
                    if(this->event.key.code == sf::Keyboard::Escape)
                        this->window->close();
                }
            }
        }
        // konstruktor
        Game::Game() {
            this->initializeVariables();
            this->initializeWindow();
        }
        // destruktor
        Game::~Game() {
            delete this->window;
        }
        // funkcja
        void Game::update() {
            this->updateEvents();
        }
        // funkcja
        void Game::render() {
            this->window->clear();
            this->window->display();
        }