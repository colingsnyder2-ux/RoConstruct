// from server: 95% by atomic.potato
struct S_func_0064bb90
{
    char pad0[0x4c];
    void *m_field4c;
    void *f();
};

extern "C" void *__cdecl func_007a8bea(void *, void *, int, int, int);

void *S_func_0064bb90::f()
{
    void *p = func_007a8bea(m_field4c, 0, (int)0xb78e40, (int)0xbb83e4, 0);
    if (p)
        return *(void **)((char *)p + 0x98);
    return 0;
}
