// from server: 100% by king_originala
struct Primitive;

struct Owner {
    void activate(Primitive* primitive);
    void deactivate(Primitive* primitive);
};

struct Primitive {
    char reserved0[0x58];
    Owner* owner;
    char reserved1[0x4c];
    bool flag0;
    bool flag1;
    bool flag2;

    void func_005e8140(bool value);
};

void Primitive::func_005e8140(bool value)
{
    bool previous = flag0 || flag1 || flag2;
    if (flag2 != value) {
        flag2 = value;
        bool current = flag0 || flag1 || flag2;
        if (current != previous && owner) {
            if (current)
                owner->activate(this);
            else
                owner->deactivate(this);
        }
    }
}
