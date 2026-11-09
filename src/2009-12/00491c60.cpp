// from server: 100% by atomic.potato
struct S
{
    void f(float const *p);
    char pad[32];
    float a;
    float b;
    float c;
};

void S::f(float const *p)
{
    a = p[0];
    b = p[1];
    c = p[2];
}
