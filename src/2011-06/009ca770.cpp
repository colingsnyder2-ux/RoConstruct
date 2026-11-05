// from server: 37% by atomic.potato
struct S
{
    int value;
    float f();
};

float S::f()
{
    if (value < 0x1ab3f00)
        return 0.0f;
    return 1.0f;
}
