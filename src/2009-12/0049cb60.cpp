// from server: 94% by atomic.potato
struct S_0049cb60 {
    struct VTable {
        void (__thiscall *f)(void *, void *, void *);
    };

    char pad[24];
    void *value;
    void f(void *, void *);
};

void S_0049cb60::f(void *a, void *b)
{
    VTable *v = *(VTable **)a;
    v->f(a, value, b);
}
