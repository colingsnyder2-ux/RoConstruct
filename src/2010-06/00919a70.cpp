// from server: 57% by atomic.potato
struct S
{
    float f();
};

float g_00a126e0 = 1.0f;

float S::f()
{
    volatile unsigned long value = *(unsigned long *)this;
    if (value < 0x1ab3f00UL)
        return g_00a126e0;
    return 1.0f;
}
