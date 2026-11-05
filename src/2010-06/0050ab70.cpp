// from server: 65% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

struct T
{
    int f(int, int);
};

extern "C" T *g(T *);
extern "C" void __stdcall h(S *, const S *, double);

int T::f(int a, int b)
{
    T *p = g(this);
    double d = *(float *)((char *)p + 0xd8);
    h((S *)this, (const S *)a, d);
    return b;
}
