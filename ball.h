#ifndef BALL_H
#define BALL_H
#include <object.h>

class Ball : public Object
{
private:
    sf::Vector2f velocity;
    float speed=200;
public:
    Ball(const sf::Texture &texture);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
    sf::Vector2f getVelocity();

    sf::Vector2f changeVelocity_x();
    sf::Vector2f changeVelocity_y();
};

#endif // BALL_H
