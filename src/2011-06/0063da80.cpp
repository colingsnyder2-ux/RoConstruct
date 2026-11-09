// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0063da80;
extern void* g_b_0063da80;
extern void* g_c_0063da80;
extern "C" void atexit_fn_0063da80(void*);
struct X_0063da80 {
    X_0063da80(int flags);
    virtual void f_0063da80();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0063da80();
};
X_0063da80::X_0063da80(int flags) : m_a(&g_a_0063da80), m_b(&g_b_0063da80), m_c(&g_c_0063da80)
{
    init_0063da80();
    if (flags & 1)
        atexit_fn_0063da80(this);
}
