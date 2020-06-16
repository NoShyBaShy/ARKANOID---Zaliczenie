#ifndef GAME_H
#define GAME_H
#include <player.h>
#include <background.h>
#include <ball.h>
#include <block.h>
#include <mod.h>
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
    int balls_created;
    int xScale;
    int Points;
    int HP;

    void update();
    void draw();
    void collision(std::vector<Object*> &objects);
    void setMod(std::vector<Object*> &objects);
    bool destroy();
    void loadTextures();

    void lvl_1();
    bool lvl_1_complete();
    bool lvl_1_defeat();
    int change_xScale(int xscale);
    int changeHP(int hp);
    int changePoints(int points);

public:
    Game();
    //~Game();
    void start();
};

#endif // GAME_H
