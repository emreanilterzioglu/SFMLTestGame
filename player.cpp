#include "player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    moveAnimation(texture,imageCount, switchTime){
    
    this->speed = speed;
    rowSelection = 0;
    faceRight = true;
    
    body.setTexture(*texture);
    moveAnimation.update(rowSelection, switchTime, true);
    body.setTextureRect(moveAnimation.uvRect);
    body.setOrigin((moveAnimation.uvRect.width/2.0f),(moveAnimation.uvRect.height/2.0f));
    body.setPosition(700,700);

}

void Player::draw(sf::RenderWindow* window){

    window->draw(body);
}


void Player::update(float deltaTime){

    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {  
        movement.x += speed * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {  
        movement.x -= speed * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (playerGroundLevel != 0))
    {
        jumpEvent();
        rowSelection = 5;
        moveAnimation.update(rowSelection, deltaTime, faceRight);
        body.setTextureRect(moveAnimation.uvRect);
    }

    if(movement.x == 0.0f)
    {
        rowSelection = 0;
    }
    else
    {
        rowSelection = 1;
        
        if(movement.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    
    moveAnimation.update(rowSelection, deltaTime, faceRight);
    body.setTextureRect(moveAnimation.uvRect);
    body.move(movement);
    std::cout << "Movement " << (float)movement.x << std::endl;
}

void Player::jumpEvent(){

    if(playerDirection != (int)directions::STEADY){
        if(playerDirection == (int)directions::UP){
            if(playerGroundLevel <= 200){
                playerGroundLevel++;
                body.move(0.f,-0.2f);
            }//Go upside
            else{playerDirection = (int)directions::DOWN;} // Start to Go downside
        }
        else if(playerDirection == (int)directions::DOWN){
            if(playerGroundLevel > 0){
                playerGroundLevel--;
                body.move(0.f,0.2f);
            }
            else{
                playerGroundLevel = 0;
                playerDirection = (int)directions::STEADY;
                score++;
            }
        }

    }
    else{
        playerDirection = (int)directions::UP;
    }

}
