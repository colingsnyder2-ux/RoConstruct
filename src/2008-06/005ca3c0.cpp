// from server: 100% by atomic.potato
float g_0081c3b8;

struct S
{
    float f();
};

float S::f()
{
    if (*((unsigned char*)this + 6))
        return 1.0f;
    if (*((unsigned char*)this + 7))
        return g_0081c3b8;
    return 0.0f;
}
