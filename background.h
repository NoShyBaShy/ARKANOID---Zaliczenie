#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <object.h>

class Background : public Object
{
public:
    Background(const sf::Texture &texture,const sf::IntRect &rect,const sf::Vector2f &pos);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);

    virtual int mod_ID();
};

#endif // BACKGROUND_H
