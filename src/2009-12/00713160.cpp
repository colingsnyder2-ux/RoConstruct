// from server: 100% by sophus
struct Color3
{
    float x, y, z;
};

struct S
{
    Color3 get();
};

Color3 S::get()
{
    Color3 c;
    c.x = *(float *)((char *)this + 0x1bc);
    c.y = *(float *)((char *)this + 0x1c0);
    c.z = *(float *)((char *)this + 0x1c4);
    return c;
}
