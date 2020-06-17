#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "MainMenuState.h"

class Game{
    private:
        //Zmienne
        
        sf::RenderWindow* window;
        sf::Event event;

        sf::Clock dtClock;
        //Logika
        float dt;

        //obiekty
        
        std::stack<State*> states;
        
        //funkcje prywatne
        void initializeVariables();
        void initWindow();
        void initStates();
    public:
        //konstruktor
        
        Game();
        
        //destruktor
        
        virtual ~Game();
        
        //akcesory
        
        const bool getEndGame() const;
        const bool windowIsOpen() const;
        
        //funkcje

        //update
        void updateDt();
        void updateEvents();
        void update();

        //render

        void render();
        void run();
};


#endif