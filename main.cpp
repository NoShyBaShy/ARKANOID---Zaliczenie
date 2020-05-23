#include "class.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Let's Bounce");
    sf::Clock clock;
    sf::Vector2f start_pos(400,550);

    Player player(start_pos);
    Background background;
    player.createSprite();
    background.createSprite();
    while(window.isOpen()){

        sf::Time elapsed = clock.restart();
        player.animate(elapsed);
        player.screen_collision();
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(player);

        window.display();

    }
    return 0;
}
