// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_008c8100;
extern void* g_b_008c8100;
extern void* g_c_008c8100;
extern "C" void atexit_fn_008c8100(void*);
struct X_008c8100 {
    X_008c8100(int flags);
    virtual void f_008c8100();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_008c8100();
};
X_008c8100::X_008c8100(int flags) : m_a(&g_a_008c8100), m_b(&g_b_008c8100), m_c(&g_c_008c8100)
{
    init_008c8100();
    if (flags & 1)
        atexit_fn_008c8100(this);
}
