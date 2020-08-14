#include "main.hpp"
#include "player.hpp"
#include "hud.hpp"
#include "scene.hpp"

bool paused = true;

static const float WINDOW_WIDTH = 1280.0f;
static const float WINDOW_HEIGHT = 768.0f;

static const float PLAYER_SPEED = 100.0f;
static const float PLAYER_ANIMATION_TIME = 0.1f; //0.1 = 10fps


void resizeView(sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(WINDOW_WIDTH/2.0f * aspectRatio, WINDOW_HEIGHT/2.0f * aspectRatio); 

}

int main()
{
    srand((int)time(0));

    sf::VideoMode vm(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow window(vm, "Window");
    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(WINDOW_WIDTH/2.0f,WINDOW_HEIGHT/2.0f));
    resizeView(window,view);

    Scene scene;


    //Player Initialize
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/tux_from_linux.png");
    Player player(&playerTexture,sf::Vector2u(3,9),PLAYER_ANIMATION_TIME,PLAYER_SPEED);



    HUD pauseText("           Paused\n Press P for Unpause\n");
    pauseText.setScale(1.f, 1.f);
    pauseText.setPosition((player.getPosition().x - 150),
                        (player.getPosition().y - 150 ));
                        
    HUD scoreText(std::to_string(player.score));
    scoreText.setScale(1.5f, 1.5f);
    scoreText.setString(std::to_string(player.score));
    scoreText.setPosition((player.getPosition().x - 350),
                        (player.getPosition().y - 350 ));


    int32_t debounceCounter = 0;

    float deltaTime = 0;
    sf::Clock clock; 

    while (window.isOpen())
    {
        if(debounceCounter < -2000000000) debounceCounter = -1; //DebounceCounter overflow check.
        debounceCounter--;
        
        deltaTime = clock.restart().asSeconds();

        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
                resizeView(window,view);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {  
            //std::cout << "Paused  " << debounceCounter <<  std::endl;
            pauseText.setPosition((view.getCenter().x - (view.getSize().x / 2.0f)) + 420,
                     (view.getCenter().y - (view.getSize().y / 2.0f)) + 50 ); 

            if(debounceCounter < 0){
                if(paused) paused = false;
                else paused = true;
                debounceCounter = 100;
            }
        }

        if(!paused){

            scene.update(deltaTime);

            scoreText.setString(std::to_string(player.score));
            std::cout << player.score << std::endl;
            scoreText.setPosition((view.getCenter().x - (view.getSize().x / 2.0f)) + 10,
                     (view.getCenter().y - (view.getSize().y / 2.0f)) +10 ); 
            player.update(deltaTime);
        
        }
        



        view.setCenter(player.getPosition().x,player.getPosition().y-250);

        window.clear();
        window.setView(view);

        scene.draw(&window);
        window.draw(scoreText);
        player.draw(&window);

        if(paused) window.draw(pauseText);

        window.display();
    }

    return 0;
}
