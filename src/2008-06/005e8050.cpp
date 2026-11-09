// from server: 100% by king_originala
struct Primitive;

struct Owner {
    void enable(Primitive*);
    void disable(Primitive*);
};

struct Primitive {
    char reserved0[0x58];
    Owner* owner;
    char reserved1[0x4C];
    bool flag0;
    bool flag1;
    bool flag2;

    void func_005e8050(bool value);
};

void Primitive::func_005e8050(bool value)
{
    bool wasEnabled = flag0 || flag1 || flag2;
    if (flag0 != value) {
        flag0 = value;
        bool isEnabled = flag0 || flag1 || flag2;
        if (isEnabled != wasEnabled && owner) {
            if (isEnabled)
                owner->enable(this);
            else
                owner->disable(this);
        }
    }
}
