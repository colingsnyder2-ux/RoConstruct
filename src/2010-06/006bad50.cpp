// from server: 100% by atomic.potato
struct S
{
    char pad[64];
    float x40;
    float x44;
    float x48;
    float x4c;
    void f(float *p);
};

void S::f(float *p)
{
    p[0] = x40;
    p[1] = x44;
    p[2] = x48;
    p[3] = x4c;
}
