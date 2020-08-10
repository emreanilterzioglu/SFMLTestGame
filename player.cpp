#include "player.hpp"

Player::Player(){


}

void Player::jumpEvent(){

    if(playerDirection != 0){
        if(playerDirection == 3){
            if(playerGroundLevel <= 200){
                playerGroundLevel++;
                this->move(0.f,-0.2f);
            }//Go upside
            else{playerDirection = 4;} // Start to Go downside
        }
        else if(playerDirection == 4){
            if(playerGroundLevel > 0){
                playerGroundLevel--;
                this->move(0.f,0.2f);
            }
            else{
                playerGroundLevel = 0;
                playerDirection = 0;
            }
        }

    }
    else{
        playerDirection = 3;
    }

}