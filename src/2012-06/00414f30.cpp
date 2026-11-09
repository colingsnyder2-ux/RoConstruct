// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00414f30;
extern void* g_b_00414f30;
extern void* g_c_00414f30;
extern "C" void atexit_fn_00414f30(void*);
struct X_00414f30 {
    X_00414f30(int flags);
    virtual void f_00414f30();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00414f30();
};
X_00414f30::X_00414f30(int flags) : m_a(&g_a_00414f30), m_b(&g_b_00414f30), m_c(&g_c_00414f30)
{
    init_00414f30();
    if (flags & 1)
        atexit_fn_00414f30(this);
}
