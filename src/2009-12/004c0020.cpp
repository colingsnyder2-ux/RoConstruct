// from server: 87% by atomic.potato
struct S
{
    void f(float *p);
    char pad[0x9c];
    float x;
    float y;
    float z;
};

void S::f(float *p)
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}
