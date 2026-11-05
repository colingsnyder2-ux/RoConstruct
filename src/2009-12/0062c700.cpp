// from server: 88% by atomic.potato
struct S
{
    int f();
    int a[98];
};

extern "C" S *__cdecl create_S();

int S::f()
{
    S *p = create_S();
    return (p->a[98] - p->a[97]) >> 3;
}
