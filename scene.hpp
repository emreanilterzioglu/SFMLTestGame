#include "cloud.hpp"
#include "player.hpp"

static const int CLOUD_COUNT = 100;

static const float MAP_WIDTH = 10000.0f;
static const float MAP_HEIGHT = 768.0f;

static const float PLAYER_SPEED = 100.0f;
static const float PLAYER_ANIMATION_TIME = 0.1f; //0.1 = 10fps


class Scene {

public:
    Scene();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    sf::Vector2f getPlayerPosition();
    int getPlayerScore();

private:

public:

private:
    Cloud cloud;
    Player* player;
    sf::Texture playerTexture;

    Collider collider;

    sf::Texture textureBackground;
    sf::Sprite spriteBackground;

    sf::Texture textureBarricade;
    Entity barricadeLeft;
    Entity barricadeRight;

    std::vector<Entity*> objList;



};