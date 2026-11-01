// from server: 100% by king_originala
struct Ball
{
    unsigned char padding[0xa8];
    unsigned char flagA;
    unsigned char reserved[2];
    unsigned char flagB;

    int getBulletSphereShape() const;
};

struct Owner
{
    void* f();
};

struct Landed
{
    unsigned char padding[4];
    Owner* owner;

    int f(Ball* ball);
};

int Landed::f(Ball* ball)
{
    Ball* current = static_cast<Ball*>(owner->f());
    int result = 2;

    if (ball->flagA || ball->flagB ||
        (current &&
         current->getBulletSphereShape() == ball->getBulletSphereShape()))
    {
        result = 1;
    }

    return result;
}
