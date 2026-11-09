// from server: 100% by atomic.potato
struct S
{
    int vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;

    void f(void *, float *);
};

void S::f(void *p, float *value)
{
    int x = p ? (int)((char *)p - 28) : 0;
    float v = *value;
    void (__thiscall *fn)(int, float) = (void (__thiscall *)(int, float))field10;
    fn(field14 + x, v);
}
