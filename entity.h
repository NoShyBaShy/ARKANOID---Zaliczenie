#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Entity
{
protected:
    sf::Sprite sprite;

    bool destroy;
public:
    Entity(const sf::Texture &texture);
    virtual ~Entity() = default;

    sf::FloatRect getBounds();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    virtual void animate(const float &elapsed)=0;
    virtual void update(const float &elapsed)=0;
    void del();
    void draw(sf::RenderTarget &render_target);
};

#endif // ENTITY_H
