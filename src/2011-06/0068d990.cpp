// from server: 54% by atomic.potato
struct S
{
    int f(int);
    int m_1c;
};

typedef int (__thiscall *Fn)(void *, void *);

extern int __cdecl G1_func_0068d8b0(int, int);

int S::f(int value)
{
    void *p = *(void **)((char *)m_1c);
    Fn fn = *(Fn *)((char *)p + 8);
    int result = fn((void *)m_1c, &value);
    return G1_func_0068d8b0((int)this, result);
}
