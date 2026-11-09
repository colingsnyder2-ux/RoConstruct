// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_007b7120;
extern void* g_b_007b7120;
extern void* g_c_007b7120;
extern "C" void atexit_fn_007b7120(void*);
struct X_007b7120 {
    X_007b7120(int flags);
    virtual void f_007b7120();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_007b7120();
};
X_007b7120::X_007b7120(int flags) : m_a(&g_a_007b7120), m_b(&g_b_007b7120), m_c(&g_c_007b7120)
{
    init_007b7120();
    if (flags & 1)
        atexit_fn_007b7120(this);
}
