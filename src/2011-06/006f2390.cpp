// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006f2390;
extern void* g_b_006f2390;
extern void* g_c_006f2390;
extern "C" void atexit_fn_006f2390(void*);
struct X_006f2390 {
    X_006f2390(int flags);
    virtual void f_006f2390();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006f2390();
};
X_006f2390::X_006f2390(int flags) : m_a(&g_a_006f2390), m_b(&g_b_006f2390), m_c(&g_c_006f2390)
{
    init_006f2390();
    if (flags & 1)
        atexit_fn_006f2390(this);
}
