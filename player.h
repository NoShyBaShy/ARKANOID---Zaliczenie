#ifndef PLAYER_H
#define PLAYER_H
#include <object.h>

class Player : virtual public Object
{
private:    
    int speed;
public:
    Player(const sf::Texture &texture,const sf::Vector2f &position,int xscale);
    Player();

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
    virtual int mod_ID();
};

#endif // PLAYER_H
