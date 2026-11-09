// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    struct V
    {
        char pad[0x148];
        void (__thiscall *fn)(void *, int, int, int);
    };

    V *v = *(V **)this;
    v->fn(this, 0, 1, 0);
}
