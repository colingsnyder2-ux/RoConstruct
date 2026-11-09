// from server: 100% by atomic.potato
struct S_func_004dd930
{
    unsigned char *m_vtable;
};

S_func_004dd930 * __cdecl f(S_func_004dd930 *p)
{
    while (p->m_vtable[0x161] == 0)
        p = *(S_func_004dd930 **)p;
    return p;
}
