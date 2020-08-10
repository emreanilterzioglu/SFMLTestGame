#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Cloud : public sf::Sprite{

public :
    float xPos;
    float yPos;
    float speed;
    int direction;

    Cloud();
    void cloudPosGen();


};
