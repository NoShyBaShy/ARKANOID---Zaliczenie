#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <object.h>

class Background : public Object
{
public:
    Background(const sf::Texture &texture);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
};

#endif // BACKGROUND_H
