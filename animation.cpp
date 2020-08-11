#include "animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    //Create Mask Rectangle for animation selection.
    uvRect.width = texture->getSize().x / imageCount.x;
    uvRect.height = texture->getSize().y / imageCount.y;
}

void Animation::update(int rowSelection, float deltaTime, bool faceRight){

    currentImage.y = rowSelection;
    totalTime += deltaTime;

    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x)
            currentImage.x = 0;

        uvRect.top  = currentImage.y * uvRect.height;

        if(faceRight){
            uvRect.left = currentImage.x * abs(uvRect.width);
            uvRect.width = abs(uvRect.width);
        }
        else
        {
            uvRect.left = (currentImage.x + 1) * abs(uvRect.width); //To Mirror image use next image's start point. Now actually left is right :)
            uvRect.width = -abs(uvRect.width); //Use abs to get always positive value.
        }
    }
}