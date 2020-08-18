#include <iostream>
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:
    Entity();
    sf::Vector2f getMidPoint();
    
private:

public:
    //Variables for collider.
    bool canMove = true;
    float penetration = 1.0f;
    float weight = 0.1f;

};
