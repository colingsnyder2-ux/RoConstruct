// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3
{
    float x, y, z;
};

extern char property;

struct S
{
    unsigned char padding[0x1b4];
    int mask;
    int state;
    unsigned char gap[8];
    float x, y, z;

    void notify(const void*);
    void f(const Vector3&);
};

void S::f(const Vector3& value)
{
    if (x != value.x || y != value.y || z != value.z)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        notify(&property);
    }

    state = state ? 1 : 2;
    mask = state == 2 ? 0xf0 : 0;
}
