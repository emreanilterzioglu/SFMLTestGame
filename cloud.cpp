#include "cloud.hpp"

Cloud::Cloud(){

    xPos = rand()%500;
    yPos = rand()%50;
    direction = rand()%2;
    speed = (float)(rand()%5) / 100.0f;
    //std::cout << "Xpos " << xPos << "Ypos " << yPos << "moveDir " << direction <<  "Speed " << speed << std::endl;

}

void Cloud::cloudPosGen(){

        if(xPos >= 600){
            direction = 0;
            speed = (float)(rand()%5) / 100.0f;
        }
        else if(xPos <= 50){
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