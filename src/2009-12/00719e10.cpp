// from server: 84% by atomic.potato
struct S
{
    char padding[0xd8];
    void *value;

    void f();
};

void S::f()
{
    void *p = value;
    void (__thiscall *fn)(void *);
    fn = *(void (__thiscall **)(void *))(*(char **)p + 0x14);
    fn(p);
}
