// from server: 61% by atomic.potato
extern float g_009cf458;

struct S
{
    void f(float *p);
};

void S::f(float *p)
{
    *(unsigned int *)p = 0;
    p[1] = g_009cf458;
}
