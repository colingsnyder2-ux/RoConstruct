// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00666630;
extern void* g_b_00666630;
extern void* g_c_00666630;
extern "C" void atexit_fn_00666630(void*);
struct X_00666630 {
    X_00666630(int flags);
    virtual void f_00666630();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00666630();
};
X_00666630::X_00666630(int flags) : m_a(&g_a_00666630), m_b(&g_b_00666630), m_c(&g_c_00666630)
{
    init_00666630();
    if (flags & 1)
        atexit_fn_00666630(this);
}
