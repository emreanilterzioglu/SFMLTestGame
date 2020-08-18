#include "collider.hpp"

Collider::Collider()
{

}

void Collider::checkCollision(std::vector<Entity*>* objList){

    float deltaX, deltaY, intersectX, intersectY;

    for(int i=0; i < (objList->size()); i++){

        if(objList->at(i)->canMove == true){
            for(int j=0; j < (objList->size()); j++){
                    
                 if(objList->at(j)->canMove == false){
                     
                    deltaX = objList->at(i)->getMidPoint().x - objList->at(j)->getMidPoint().x;
                    deltaY = objList->at(i)->getMidPoint().y - objList->at(j)->getMidPoint().y; 

                    intersectX = abs(deltaX) - (abs(((objList->at(i)->getTextureRect().width)/2)) + abs(((objList->at(j)->getTextureRect().width)/2)));
                    intersectY = abs(deltaY) - (abs(((objList->at(i)->getTextureRect().height)/2)) + abs(((objList->at(j)->getTextureRect().height)/2)));

                    if((intersectX < 0) && (intersectY < 0)){
                       // objList->at(i)->move();

                        std::cout << "Collusion detected!! " << intersectX << "  " <<  intersectY << std::endl << std::endl;
                       
                    } 
                 }
            }
        }
    }

}

