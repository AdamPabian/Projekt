#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <map>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class State {
    private:

    protected:
        sf::RenderWindow* window;
        bool quit;
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::stack<State*>* states;
    public:
        State(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~State();

        const bool& getQuit() const;

        virtual void checkForQuit();
        virtual void updateMousePosition();
        //funkcja czysto wirtualna
        virtual void endState() = 0;
        virtual void updateKeybinds() = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif