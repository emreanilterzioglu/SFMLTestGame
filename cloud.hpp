#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class Cloud {

public :
    Cloud(int _mapwidth,int _cloudCount);
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    void init();

private:

public :

private:
    sf::Texture textureCloud;
    int activeWidth = 0;
    int mapWidth = 0;
    int cloudCount = 0;
    std::vector <sf::Sprite> clouds;
    std::vector <int> direction;
    std::vector <float> speed;


};
