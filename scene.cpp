#include "scene.hpp"

Scene::Scene() :
    cloud(MAP_WIDTH,CLOUD_COUNT)
{

//Background Initialize
    textureBackground.setRepeated(true);
    textureBackground.loadFromFile("images/background.png");

    spriteBackground.setTexture(textureBackground);
    //spriteBackground.setOrigin(textureBackground.getSize().x/2.0f,textureBackground.getSize().y/2.0f);
    spriteBackground.setOrigin(0,0);
    spriteBackground.setPosition(-(MAP_WIDTH/2.0f),0.f);
    spriteBackground.setTextureRect(sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(MAP_WIDTH,MAP_HEIGHT)));

    barricadeLeft.setSize(sf::Vector2f(25.0f, 200.0f));
    barricadeLeft.setPosition(0.0f, 600.0f);
    barricadeLeft.setFillColor(sf::Color::Red);
       
    barricadeRight.setSize(sf::Vector2f(25.0f, 200.0f));
    barricadeRight.setPosition(1280.0f, 600.0f);
    barricadeRight.setFillColor(sf::Color::Red);


}

void Scene::draw(sf::RenderWindow* window){
    
    window->draw(spriteBackground);
    cloud.draw(window);
    window->draw(barricadeLeft);
    window->draw(barricadeRight);

}

void Scene::update(float deltaTime){

    cloud.update(deltaTime);
}