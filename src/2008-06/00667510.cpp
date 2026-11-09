// from server: 100% by king_originala
extern float factor;

struct Input {
    virtual void unused();
    virtual float value(int);
};

struct Vector {
    float x, y, z;
};

struct S {
    char padding[0xA8];
    float rate;
    char gap[8];
    float x, y, z;

    Vector* sample(Vector*);
    void f(int, Input*);
};

void S::f(int, Input* input)
{
    rate = input->value(3) * factor;
    Vector temporary;
    Vector* result = sample(&temporary);
    x = result->x;
    y = result->y;
    z = result->z;
}
