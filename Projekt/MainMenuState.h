#ifndef MENU_H
#define MENU_H

#include "State.h"
#include "GameState.h"

class MainMenuState : public State {
    private:

        sf::RectangleShape background;
        sf::RectangleShape exitButton;
        sf::RectangleShape startButton;
        sf::Text startText;
        sf::Text exitText;
        sf::Font font;
        bool mouseHeld = false;
        void initFonts();
        void initText();

    public:
        MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~MainMenuState();

        void endState();
        void updateKeybinds();
        void makeButtons();
        void updateText();
        void updateButtons();
        void update();
        void renderButtons();
        void renderText();
        void render(sf::RenderTarget* target = NULL);
};

#endif