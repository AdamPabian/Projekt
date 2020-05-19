#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game {
    private:
        //Okno
        sf::RenderWindow* window;
        sf::Event event;
        //Funkcje prywatne
        void initializeVariables();
        void initializeWindow();
    public: //Konstruktory i destruktory
        const bool windowOpen() const;
        Game();
        virtual ~Game();
        //Funkcje
        void updateEvents();
        void update();
        void render();
};

#endif