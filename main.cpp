#include "main.hpp"
#include "cloud.hpp"
#include "player.hpp"

bool paused = true;

int main()
{
    srand((int)time(0));

    sf::VideoMode vm(640, 241);
    sf::RenderWindow window(vm, "Window");
    
    sf::Texture textureBackground;
    textureBackground.loadFromFile("images/background2.png");
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    //Player Initialize
    Player player;
    player.setPosition(30,170);
    sf::Texture texturePlayer;
    texturePlayer.loadFromFile("images/knight.png");   
    player.setTexture(texturePlayer);

    //Cloud Initialize
    Cloud cloud1;
    Cloud cloud2;
    Cloud cloud3;

    sf::Texture textureCloud;
    textureCloud.loadFromFile("images/cloud.png");   
    cloud1.setTexture(textureCloud);
    cloud2.setTexture(textureCloud);
    cloud3.setTexture(textureCloud);

    int32_t debounceCounter = 0;

    while (window.isOpen())
    {
        if(debounceCounter < -2000000000) debounceCounter = -1; //DebounceCounter overflow check.
        debounceCounter--;
        
        sf::Event event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {  
            std::cout << "Paused  " << debounceCounter <<  std::endl;
            if(debounceCounter < 0){
                if(paused) paused = false;
                else paused = true;
                debounceCounter = 100;
            }
        }

        if(!paused){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {  
                player.move(0.1f,0.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {  
                player.move(-0.1f,0.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (player.playerGroundLevel != 0))
            {
                player.jumpEvent();
            }
        /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {  
                shapePlayer.move(0.f,0.1f);
            }*/

            cloud1.cloudPosGen();
            cloud2.cloudPosGen();
            cloud3.cloudPosGen();
            cloud1.setPosition(cloud1.xPos,cloud1.yPos);
            cloud2.setPosition(cloud2.xPos,cloud2.yPos);
            cloud3.setPosition(cloud3.xPos,cloud3.yPos);

        }
        


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spriteBackground);
        window.draw(player);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);


        window.display();
    }

    return 0;
}
