#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "animation.hpp"

enum class directions{
    STEADY,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Player{

public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    void jumpEvent();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);

public :

    int direction;
    int playerGroundLevel = 0;
    int playerDirection = (int)directions::STEADY; // 0-Steady, 1-Left, 2-Right, 3-Up, 4-Down,
    int score = 0;


private :
    Animation moveAnimation;
    sf::Sprite body;

    float xPos;
    float yPos;
    float speed;
    unsigned int rowSelection;
    bool faceRight;
};
