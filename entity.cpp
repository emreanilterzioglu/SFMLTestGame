#include "entity.hpp"

Entity::Entity()
{

}

sf::Vector2f Entity::getMidPoint(){
    
    return sf::Vector2f((this->getPosition().x + (abs(this->getTextureRect().width)/2)),
                    (this->getPosition().y + (abs(this->getTextureRect().height)/2)));

}
