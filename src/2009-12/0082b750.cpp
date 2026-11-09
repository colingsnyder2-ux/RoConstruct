// from server: 78% by atomic.potato
struct S
{
    int f(void *, void *);
};

typedef int (__thiscall *T)(void *, void *, int);

int S::f(void *a, void *p)
{
    T q = *(T *)((char *)*(void **)this + 0x14c);
    q(this, p, 0);
    return (int)p;
}
