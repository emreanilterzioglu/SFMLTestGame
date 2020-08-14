#include "cloud.hpp"

Cloud::Cloud(int _mapwidth,int _cloudCount){

    this->mapWidth = _mapwidth;
    this->cloudCount = _cloudCount;
    this->activeWidth = _mapwidth / 2;

    //std::cout << "Xpos " << xPos << "Ypos " << yPos << "moveDir " << direction <<  "Speed " << speed << std::endl;

    init();

}

void Cloud::init(){

    //Cloud Initialize
    textureCloud.loadFromFile("images/cloud.png");  
    for(int i=0; i<cloudCount; i++){
        clouds.push_back(sf::Sprite());
        direction.push_back(int());
        speed.push_back(float());

        clouds[i].setTexture(textureCloud);
        clouds[i].setScale(1.5f,1.5f);
        clouds[i].setPosition(((rand()%mapWidth) - activeWidth),
                            ((rand()%100)+150));
        direction[i] = rand()%2;
        speed[i] = (float)(rand()%5) / 100.0f;
    }
}

void Cloud::draw(sf::RenderWindow* window){

    for(int i=0; i<cloudCount; i++){
        window->draw(clouds[i]);
    }
}

void Cloud::update(float deltaTime){

    float xPos = 0;
    float yPos = 0;

    for(int i=0; i<cloudCount; i++){
        xPos = clouds[i].getPosition().x;
        yPos = clouds[i].getPosition().y;
        if(xPos >= activeWidth){
            direction[i] = 0;
            speed[i] = (float)(rand()%5) / 100.0f;
        }
        else if(xPos <= -activeWidth){
            direction[i] = 1;
            speed[i] = (float)(rand()%5) / 100.0f;
        }

        if(direction[i]){
            xPos = xPos + (0.01f + speed[i]);
        }
        else{
            xPos = xPos - (0.01f + speed[i]);
        }   

        clouds[i].setPosition(xPos, yPos);
 
    }

}