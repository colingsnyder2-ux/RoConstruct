// from server: 47% by atomic.potato
struct S
{
    void f(float, float, float);
};

void S::f(float a, float b, float c)
{
    S* p = (S*)((char*)this + 16);
    p->f(c, a, b);
}
