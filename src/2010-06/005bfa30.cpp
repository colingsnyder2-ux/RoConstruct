// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005bfa30;
extern void* g_b_005bfa30;
extern void* g_c_005bfa30;
extern "C" void atexit_fn_005bfa30(void*);
struct X_005bfa30 {
    X_005bfa30(int flags);
    virtual void f_005bfa30();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005bfa30();
};
X_005bfa30::X_005bfa30(int flags) : m_a(&g_a_005bfa30), m_b(&g_b_005bfa30), m_c(&g_c_005bfa30)
{
    init_005bfa30();
    if (flags & 1)
        atexit_fn_005bfa30(this);
}
