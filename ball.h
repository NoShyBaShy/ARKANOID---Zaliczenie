#ifndef BALL_H
#define BALL_H
#include <object.h>

class Ball : public Object
{
private:
    bool is_release;
    sf::Vector2f velocity;
    float speed;
public:
    Ball(const sf::Texture &texture);
    Ball(const sf::Texture &texture,const float &pos_x);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);

    virtual int mod_ID();
    sf::Vector2f getVelocity();

    sf::Vector2f changeVelocity_x();
    sf::Vector2f changeVelocity_y();
};

#endif // BALL_H
