// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00411620;
extern void* g_b_00411620;
extern void* g_c_00411620;
extern "C" void atexit_fn_00411620(void*);
struct X_00411620 {
    X_00411620(int flags);
    virtual void f_00411620();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00411620();
};
X_00411620::X_00411620(int flags) : m_a(&g_a_00411620), m_b(&g_b_00411620), m_c(&g_c_00411620)
{
    init_00411620();
    if (flags & 1)
        atexit_fn_00411620(this);
}
