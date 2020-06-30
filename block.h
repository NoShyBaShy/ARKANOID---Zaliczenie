#ifndef BLOCK_H
#define BLOCK_H
#include <object.h>


class Block : public Object
{
private:

public:
    Block(const sf::Texture &texture,const sf::Vector2f &pos, int hp);
    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
    virtual int mod_ID();
};

#endif // BLOCK_H
