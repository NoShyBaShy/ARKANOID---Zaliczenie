#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>



class Player : public sf::Sprite{
private:
    sf::Vector2f velocity = {0.f,0.f};
    int speed = 300.f;
    bool is_large=false;
    bool is_medium=true;
    bool is_small=false;

    bool faster = false;
    bool slower = false;
    bool normal = false;

    bool swap = false;

    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
public:
    Player(const sf::Vector2f &position) : sf::Sprite(){
        setPosition(position);
    };
    void loadTextures();
    void createSprite();
    void animate(const sf::Time &elapsed);
    void screen_collision();
};

class Background : public sf::Sprite{
private:
    std::vector<sf::Texture> textures;
public:
     void loadTextures();
     void createSprite();
};

class Ball : public sf::Sprite{
private:

};

#endif // WINDOW_H
