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

    textureBarricade.loadFromFile("images/brick.png");
    textureBarricade.setRepeated(true);

    barricadeLeft.setPosition(0.0f, 600.0f);
    //barricadeLeft.setColor(sf::Color::Red);
    barricadeLeft.setTexture(textureBarricade);   
    //barricadeLeft.setScale(0.2f, 0.2f);
    barricadeLeft.scale(0.2f, 0.2f);
    barricadeLeft.setTextureRect(sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(90,1000)));
    barricadeLeft.canMove = false;
    barricadeLeft.weight = 1000.0f;
    barricadeLeft.penetration = 0.0f;

    barricadeRight.setPosition(1280.0f, 600.0f);
    //barricadeRight.setColor(sf::Color::Red);
    barricadeRight.setTexture(textureBarricade);
    barricadeRight.setScale(0.2f, 0.2f);
    barricadeRight.setTextureRect(sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(90,1000)));
    barricadeRight.canMove = false;
    barricadeRight.weight = 1000.0f;
    barricadeRight.penetration = 0.0f;

//Player Initialize
    playerTexture.loadFromFile("images/tux_from_linux.png");
    player = new Player(&playerTexture,sf::Vector2u(3,9),PLAYER_ANIMATION_TIME,PLAYER_SPEED);

//Fill Obj Vector
    objList.push_back(player->getSprite());
    objList.push_back(&barricadeLeft);
    objList.push_back(&barricadeRight);



}

void Scene::draw(sf::RenderWindow* window){
    
    window->draw(spriteBackground);
    cloud.draw(window);
    player->draw(window);
    window->draw(barricadeLeft);
    window->draw(barricadeRight);
}

void Scene::update(float deltaTime){

    cloud.update(deltaTime);
    player->update(deltaTime);

    collider.checkCollision(&objList);
}

sf::Vector2f Scene::getPlayerPosition(){

  return  player->getPosition();
}

int Scene::getPlayerScore(){

  return  player->score;
}