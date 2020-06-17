#include "GameState.h"

void GameState::initializeVariables() {

    this->points = 0;
    this->enemySpawnTimerMax = 40.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->enemySizeX = 50.f;
    this->enemySizeY = 50.f;
    this->mouseHeld = false;
    this->health = 5;
    this->endGame = false;
}


void GameState::initFonts() {

    if(!this->font.loadFromFile("Fonts/PTSerif-Regular.ttf")) {
        std::cout<<"Font loading error"<<std::endl;
    }
}


void GameState::initText() {

    this->gameText.setFont(this->font);
    this->gameText.setCharacterSize(24);
    this->gameText.setFillColor(sf::Color::White);
    this->gameText.setString("NONE");
}


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) 
    : State(window, states) {
        this->initializeVariables();
        this->initFonts();
        this->initText();
}

GameState::~GameState() {

}

void GameState::endState() {

}

void GameState::updateKeybinds() {

    this->checkForQuit();
}

void GameState::spawnEnemy() {

    this->enemy.setPosition(
    static_cast<float>(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getSize().x - 100.f)+100.f),
    0.f);
    this->enemy.setSize(sf::Vector2f(enemySizeX,enemySizeY));
    this->enemy.setFillColor(sf::Color::Cyan);    
    this->enemies.push_back(this->enemy);
}

void GameState::updateText() {
    std::stringstream ss;
    ss<<"Points: "<<this->points <<"\n"
    << "Health: "<<this->health;
    this->gameText.setString(ss.str());

}

void GameState::updateEnemies() {
    
    //dodawanie przeciwnikow

    if((int)this->enemies.size() < this->maxEnemies) {

        if(this->enemySpawnTimer >= this->enemySpawnTimerMax) {

            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    //przesuwanie przeciwnikow i usuwanie ich na granicy

    for(int i=0; i < (int)(this->enemies.size());i++) {

        this->enemies[i].move(0.f, 2.f);

        if(this->enemies[i].getPosition().y>this->window->getSize().y) {

            this->enemies.erase(this->enemies.begin() + i);
            this->health = substract<int> (this->health);
        }
    }

    //sprawdza czy uzytkownik kliknal przeciwnika
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        
        if(this->mouseHeld == false) {

        //usuwanie przeciwnikow
            this->mouseHeld = true;
            bool deleted = false;
            
            for(size_t i=0;i<this->enemies.size() && deleted==false;i++) {
                
                if(this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

                deleted = true;
                this->enemies.erase(this->enemies.begin() + i);
                
                //przyznawanie punktow
                
                this->points += 5;
                }
            }
    
        }
    }
    else {
        this->mouseHeld = false;
    }

}

void GameState::update() {
    this->updateKeybinds();
    if(this->endGame == false) {

        this->updateMousePosition();
            
        this->updateText();

        this->updateEnemies();
    }
    if(this->health <= 0) {
        this->quit = true;
    }
    
}

void GameState::renderText() {
    this->window->draw(this->gameText);
}


void GameState::renderEnemies() {

    for(auto &e : this->enemies) {
        this->window->draw(e);
    }

}

void GameState::render(sf::RenderTarget*target) {
    if(!target) {
        target = this->window;
    }

    this->renderEnemies();
        
    this->renderText();
}