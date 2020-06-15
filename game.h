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

    int blocks_created;

    void update();
    void draw();
    void collision(std::vector<Object*> &objects);
    bool destroy();
    void loadTextures();

    void lvl_1();
    bool lvl_1_complete();

public:
    Game();
    //~Game();
    void start();
};

#endif // GAME_H
