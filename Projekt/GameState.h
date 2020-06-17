#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "MainMenuState.h"

template <class T>
T substract(T hp) {
    return --hp;
}


class GameState : public State {
    private:
        sf::RectangleShape background;
        sf::RectangleShape enemy;
        sf::Text gameText;
        sf::Font font;
        std::vector<sf::RectangleShape> enemies;

        int points;
        float enemySpawnTimerMax;
        float enemySpawnTimer;
        int maxEnemies;
        float enemySizeX;
        float enemySizeY;
        bool mouseHeld;
        int health;
        bool endGame;

        void initializeVariables();
        void initFonts();
        void initText();
    public:
        GameState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~GameState();

        void endState();
        void spawnEnemy();
        void updateKeybinds();
        void updateText();
        void updateEnemies();
        void update();
        void renderText();
        void renderEnemies();
        void render(sf::RenderTarget* target = NULL);

};

#endif