// from server: 39% by atomic.potato
struct S
{
    char pad[0x230];
    double f();
};

struct T
{
    char pad[8];
    double value;
};

extern "C" T *sub_005881c0(void *, int);

double S::f()
{
    T *p;
    p = sub_005881c0((char *)this + 0x230, -1);
    return p->value;
}
