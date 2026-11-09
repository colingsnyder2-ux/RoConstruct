// from server: 58% by atomic.potato
typedef void (__thiscall *Func)(void *, void *);

struct S_008efdf0
{
    char pad[24];
    void *m_func;
    void operator()(void *, void *);
};

void S_008efdf0::operator()(void *a, void *b)
{
    Func f = *(Func *)*(void **)a;
    f(b, m_func);
}
