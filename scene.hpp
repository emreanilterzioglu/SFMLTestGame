#include "cloud.hpp"

static const int CLOUD_COUNT = 100;
static const float MAP_WIDTH = 10000.0f;
static const float MAP_HEIGHT = 768.0f;


class Scene {

public:
    Scene();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);

private:

public:

private:
    Cloud cloud;
    sf::Texture textureBackground;
    sf::Sprite spriteBackground;
    sf::RectangleShape barricadeLeft;
    sf::RectangleShape barricadeRight;




};