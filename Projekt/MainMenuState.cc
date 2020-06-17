#include "MainMenuState.h"

void MainMenuState::initFonts() {

    if(!this->font.loadFromFile("Fonts/PTSerif-Regular.ttf")) {
        std::cout<<"Font loading error"<<std::endl;
    }
}

void MainMenuState::initText() {

    this->startText.setFont(this->font);
    this->startText.setCharacterSize(44);
    this->startText.setFillColor(sf::Color::White);

    this->exitText.setFont(this->font);
    this->exitText.setCharacterSize(44);
    this->exitText.setFillColor(sf::Color::White);
    this->exitText.setPosition(320.f,200.f);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) 
    : State(window, states) {
        this->initFonts();
        this->initText();
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::endState() {

}

void MainMenuState::updateKeybinds() {

    this->checkForQuit();
}

void MainMenuState::makeButtons() {

    this->startButton.setPosition(250.f,250.f);
    this->startButton.setSize(sf::Vector2f(300.f,60.f));
    this->startButton.setFillColor(sf::Color::Blue);  

    this->exitButton.setPosition(250.f,350.f);
    this->exitButton.setSize(sf::Vector2f(300.f,60.f));
    this->exitButton.setFillColor(sf::Color::Blue);

}

void MainMenuState::updateButtons() {

    this->makeButtons();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(this->mouseHeld == false) {

            this->mouseHeld = true;
            if(this->exitButton.getGlobalBounds().contains(this->mousePosView)) {

                    this->quit = true;

            }
            else if(this->startButton.getGlobalBounds().contains(this->mousePosView)) {

                    this->states->push(new GameState(this->window, this->states));
            }
        }
    }
    else {
        this->mouseHeld = false;
    }
}

void MainMenuState::updateText() {
    this->startText.setPosition(startButton.getPosition().x+startButton.getSize().x/2-44,startButton.getPosition().y);
    this->startText.setString("Start");

    this->exitText.setPosition(exitButton.getPosition().x+exitButton.getSize().x/2-44,exitButton.getPosition().y);
    this->exitText.setString("Exit");
}

void MainMenuState::update() {
    this->updateMousePosition();
    this->updateKeybinds();
    this->updateButtons();
    this->updateText();
}

void MainMenuState::renderButtons() {

    this->window->draw(this->startButton);
    this->window->draw(this->exitButton);

}

void MainMenuState::renderText() {
    this->window->draw(this->startText);
    this->window->draw(this->exitText);
}

void MainMenuState::render(sf::RenderTarget* target) {
    
    if(!target) {
        target = this->window;
    }
    this->renderButtons();
    this->renderText();
    
}