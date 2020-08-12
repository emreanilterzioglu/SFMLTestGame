#include "cloud.hpp"

Cloud::Cloud(int mapwidth){

    activeWidth = mapwidth / 2;
    xPos = (rand()%mapwidth) - activeWidth;
    yPos = (rand()%100)+150;
    direction = rand()%2;
    speed = (float)(rand()%5) / 100.0f;
    //std::cout << "Xpos " << xPos << "Ypos " << yPos << "moveDir " << direction <<  "Speed " << speed << std::endl;

}

void Cloud::cloudPosGen(){

        if(xPos >= activeWidth){
            direction = 0;
            speed = (float)(rand()%5) / 100.0f;
        }
        else if(xPos <= -activeWidth){
            direction = 1;
            speed = (float)(rand()%5) / 100.0f;
        }

        if(direction){
            xPos = xPos + (0.01f + speed);
        }
        else{
            xPos = xPos - (0.01f + speed);
        }

}