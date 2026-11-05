// from server: 73% by atomic.potato
struct S_func_009081c0
{
    S_func_009081c0 *m_next;
    char pad0[89];
    char m_flag;
    static S_func_009081c0 *f(S_func_009081c0 *);
};

S_func_009081c0 *S_func_009081c0::f(S_func_009081c0 *p)
{
    p = p->m_next;
    while (!p->m_flag)
        p = p->m_next;
    return p;
}
