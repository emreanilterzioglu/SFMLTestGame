#include <iostream>
#include <SFML/Graphics.hpp>


class Animation{

public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

    void update(int row, float deltaTime, bool faceRight);

private:

public:
    sf::IntRect uvRect;
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};