// from server: 66% by atomic.potato
struct S
{
    int f(void *, void *);
    void *m_1c;
};

extern "C" int sub_66f850(void *, void *);

int S::f(void *a, void *b)
{
    char x[8];
    void *p = *(void **)m_1c;
    p = (char *)p + 12;
    return ((int (__thiscall *)(void *, void *, int))(*(void **)p))(m_1c, b, sub_66f850(a, x));
}
