// from server: 100% by king_originala
struct S;

struct Helper
{
    unsigned char padding[8];
    void initialize(S* owner, const void* type, int flag);
};

struct S
{
    unsigned char padding[0x10C];
    Helper helper;
    int value;

    int create(int value);
    int f(int enabled);
};

int S::f(int enabled)
{
    helper.initialize(this, (const void*)0x81089C, 0);
    int argument = enabled;
    if (argument)
        argument = value;
    return create(argument) != 0;
}
