// from server: 37% by atomic.potato
struct S
{
    void f(void *, unsigned int);
};

void S::f(void *p, unsigned int)
{
    void **v = *(void ***)p;
    unsigned int r = ((unsigned int (__thiscall *)(void *))v[1])(p);
    ((void (__thiscall *)(S *, unsigned int, void *))0x006b9820)(this, r, p);
}
