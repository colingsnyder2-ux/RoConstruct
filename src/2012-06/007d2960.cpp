// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_007d2960;
extern void* g_b_007d2960;
extern void* g_c_007d2960;
extern "C" void atexit_fn_007d2960(void*);
struct X_007d2960 {
    X_007d2960(int flags);
    virtual void f_007d2960();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_007d2960();
};
X_007d2960::X_007d2960(int flags) : m_a(&g_a_007d2960), m_b(&g_b_007d2960), m_c(&g_c_007d2960)
{
    init_007d2960();
    if (flags & 1)
        atexit_fn_007d2960(this);
}
