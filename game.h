#ifndef GAME_H
#define GAME_H
#include <player.h>
#include <background.h>
#include <ball.h>
#include <block.h>

class Game
{
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Event event;
    float elapsed;

    Player *player;
    Background *background;
    Ball *ball;
    Block *block;
    std::vector<Object*> objects;

    sf::Texture texture;
    std::vector<sf::Texture> Texture;

    void update();
    void draw();
    void collision(std::vector<Object*> &objects);

    void lvl_1();


public:
    Game();
    //~Game();
    void start();
};

#endif // GAME_H
