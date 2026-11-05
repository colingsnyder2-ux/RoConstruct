// from server: 42% by atomic.potato
float g_005dd8a0;

struct S
{
    void f(float *p);
};

void S::f(float *p)
{
    p[0] = 0.0f;
    p[1] = g_005dd8a0;
}
