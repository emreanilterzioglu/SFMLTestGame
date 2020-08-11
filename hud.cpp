#include "hud.hpp"

HUD::HUD(std::string text){

    font.loadFromFile("fonts/roboto/Roboto-Black.ttf");
    this->setString(text);
    this->setCharacterSize(30);
    this->setColor(sf::Color(128,128,128));
    this->setFont(font);


}