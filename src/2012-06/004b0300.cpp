// from server: 40% by atomic.potato
struct V
{
    void (**vtable)();
};

struct S
{
    int pad0[67];
    V *v10c;
    int pad1[2];
    int v118;
    void f();
};

void S::f()
{
    v10c->vtable[2]();
    v118;
}
