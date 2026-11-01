// from server: 100% by king_originala
struct Result
{
    char padding[0x1D4];
    int state;
};

struct Interface
{
    virtual void slot0();
    virtual Result* get();
};

struct Owner
{
    char padding[0x288];
    Interface value;
};

struct S
{
    char padding[0x0C];
    Owner* owner;
    bool f();
};

bool S::f()
{
    return owner->value.get()->state == 2;
}
