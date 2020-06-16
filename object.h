#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Object
{
public:
    sf::Sprite sprite;
    bool destroy;

public:
    Object(const sf::Texture &texture);
    Object();
    virtual ~Object() = default;

    sf::FloatRect getBounds();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    virtual void animate(const float &elapsed)=0;
    virtual void update(const float &elapsed)=0;
    virtual int mod_ID()=0;
    void del();
    void draw(sf::RenderTarget &render_target);
    bool getDestroyed();
    bool is_destroyed();
};

#endif // OBJECT_H
