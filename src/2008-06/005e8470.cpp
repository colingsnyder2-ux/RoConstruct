// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

struct S;

struct Listener {
    char pad[132];
    void* member;
    void f(S*);
};

struct Shape {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void setVector(const Vector&) = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual float getValue() = 0;

    Vector value;
};

struct S {
    char pad0[0x58];
    Listener* listener;
    char pad1[0x3c];
    int state;
    Shape* shape;
    char pad2[0x50];
    unsigned char changed;

    Vector prepare(const Vector&);
    void update(float);
    void f(const Vector&);
};

#pragma float_control(precise, off, push)

void S::f(const Vector& input)
{
    Vector value = prepare(input);
    if (value.x != shape->value.x ||
        value.y != shape->value.y ||
        value.z != shape->value.z)
    {
        state = -2;
        shape->setVector(value);
        update(shape->getValue());
        if (listener)
            listener->f(this);
        changed = 1;
    }
}

#pragma float_control(pop)
