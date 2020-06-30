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
    std::vector<sf::Sound> Sounds;
    sf::Sound sound_player;
    sf::Sound sound_block;
    sf::Sound sound_powerup;
    sf::Sound sound_win;
    sf::Sound sound_lose;

    sf::SoundBuffer buffer_player;
    sf::SoundBuffer buffer_block;
    sf::SoundBuffer buffer_powerup;
    sf::SoundBuffer buffer_win;
    sf::SoundBuffer buffer_lose;

    sf::Font font;
    sf::Text score;
    sf::Text Health;
    sf::Text level;


    sf::Texture texture;
    std::vector<sf::Texture> Texture;

    int blocks_created;
    int balls_created;
    int xScale;
    int Points;
    int HP;
    int LVL;

    bool lvl_started;
    bool mod_created;


    void update();
    void draw();
    void collision(std::vector<Object*> &objects);
    void setMod(std::vector<Object*> &objects);
    bool destroy();
    void loadTextures();
    void loadMusic();
    void loadFont();
    void setFont();
    void lvl_1();
    void lvl_2();

    int lvl_complete();
;
    void reset();
    int change_xScale(int xscale);
    int changeHP(int hp);
    int changePoints(int points);

public:
    Game();
    //~Game();
    void start();
};

#endif // GAME_H
