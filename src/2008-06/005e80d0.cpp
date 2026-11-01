// from server: 100% by king_originala
struct Primitive;

struct Owner
{
    void activate(Primitive*);
    void deactivate(Primitive*);
};

struct Primitive
{
    char padding0[0x58];
    Owner* owner;
    char padding1[0x4c];
    bool flag0;
    bool flag1;
    bool flag2;

    void setFlag1(bool value);
};

void Primitive::setFlag1(bool value)
{
    bool wasActive = flag0 || flag1 || flag2;

    if (flag1 != value)
    {
        flag1 = value;
        bool isActive = flag0 || flag1 || flag2;

        if (isActive != wasActive && owner)
        {
            if (isActive)
                owner->activate(this);
            else
                owner->deactivate(this);
        }
    }
}
