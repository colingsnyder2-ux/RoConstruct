// from server: 63% by atomic.potato
struct S
{
    int v0;
    int v1;
    int v2;
    int v3;
    void *v4;

    void f();
};

typedef void (__thiscall *F)(void *);

extern "C" F g;

void S::f()
{
    v0 = 0xa5e30c;
    v3 = 0xa5e304;
    v3 = 0xa5bfdc;
    if (v4 != 0)
        (*(F *)((char *)*(void **)v4 + 0x10))(v4);
    g(this);
}
