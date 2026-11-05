// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00772660;
extern void* g_b_00772660;
extern void* g_c_00772660;
extern "C" void atexit_fn_00772660(void*);
struct X_00772660 {
    X_00772660(int flags);
    virtual void f_00772660();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00772660();
};
X_00772660::X_00772660(int flags) : m_a(&g_a_00772660), m_b(&g_b_00772660), m_c(&g_c_00772660)
{
    init_00772660();
    if (flags & 1)
        atexit_fn_00772660(this);
}
