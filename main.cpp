#include "main.hpp"
#include "cloud.hpp"
#include "player.hpp"
#include "hud.hpp"

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
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/tux_from_linux.png");
    Player player(&playerTexture,sf::Vector2u(3,9),0.3f,100.0f);

    //Cloud Initialize
    Cloud clouds[CLOUD_COUNT];

    sf::Texture textureCloud;
    textureCloud.loadFromFile("images/cloud.png");  
    for(int i=0; i<CLOUD_COUNT; i++){
        clouds[i].setTexture(textureCloud);
    }

    HUD pauseText("           Paused\n Press P for Unpause\n");
    pauseText.setScale(1.f, 1.f);
    pauseText.setPosition(200.f, 50.f); 

    HUD scoreText("0\n");
    scoreText.setScale(1.f, 1.f);
    scoreText.setPosition(10.f, 10.f); 



    int32_t debounceCounter = 0;

    float deltaTime = 0;
    sf::Clock clock; 

    while (window.isOpen())
    {
        if(debounceCounter < -2000000000) debounceCounter = -1; //DebounceCounter overflow check.
        debounceCounter--;
        
        deltaTime = clock.restart().asSeconds();

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

            for(int i=0; i<CLOUD_COUNT; i++){
                clouds[i].cloudPosGen();
                clouds[i].setPosition(clouds[i].xPos,clouds[i].yPos);
            }

            scoreText.setString(std::to_string(player.score));
            
            player.update(deltaTime);

        }
        


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(spriteBackground);

        for(int i=0; i<CLOUD_COUNT; i++){
            window.draw(clouds[i]);
        }

        window.draw(scoreText);
        player.draw(&window);
        if(paused) window.draw(pauseText);

        window.display();
    }

    return 0;
}
