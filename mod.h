#ifndef MOD_H
#define MOD_H
#include <object.h>

class Mod : public Object
{
private:
    float speed;
    int mod_identity;
public:
    Mod(const sf::Texture &texture,const sf::Vector2f &pos, int mod_number);
    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);

    int mod_ID();
};

#endif // MOD_H
