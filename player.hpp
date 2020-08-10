#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Player : public sf::Sprite{

public :
    float xPos;
    float yPos;
    float speed;
    int direction;
    int playerGroundLevel = 0;
    int playerDirection = 0; // 0-Steady, 1-Left, 2-Right, 3-Up, 4-Down,
    
    Player();
    void jumpEvent();

};
