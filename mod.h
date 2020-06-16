#ifndef MOD_H
#define MOD_H
//#include <object.h>
#include <player.h>

class Mod : virtual public Player
{
private:
    float speed;
    int mod_identity;
public:
    Mod(const sf::Texture &texture,const sf::Vector2f &pos, int mod_number);
    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
    virtual int mod_ID();
};

#endif // MOD_H
