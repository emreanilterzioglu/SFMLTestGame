#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class HUD : public sf::Text{//HeadUp Display

public :
    //float xPos;
    //float yPos;
    //float speed;
    //int direction;
    sf::Font font;

    HUD(std::string text);
    //void cloudPosGen();


};
