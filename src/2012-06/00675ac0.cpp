// from server: 46% by atomic.potato
struct S
{
    int value;
    float f();
};

float S::f()
{
    if ((unsigned int)value < 0x1ab3f00U)
        return *(const float*)0x00b62770;
    return 1.0f;
}
