// from server: 46% by atomic.potato
struct S_func_004dd910 {
    S_func_004dd910 *m_next;
    unsigned char m_flag;
    S_func_004dd910 * __cdecl f(S_func_004dd910 *);
};

S_func_004dd910 *S_func_004dd910::f(S_func_004dd910 *p)
{
    while (!p->m_flag)
        p = p->m_next;
    return p;
}
