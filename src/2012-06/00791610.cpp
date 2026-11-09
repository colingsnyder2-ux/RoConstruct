// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00791610;
extern void* g_b_00791610;
extern void* g_c_00791610;
extern "C" void atexit_fn_00791610(void*);
struct X_00791610 {
    X_00791610(int flags);
    virtual void f_00791610();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00791610();
};
X_00791610::X_00791610(int flags) : m_a(&g_a_00791610), m_b(&g_b_00791610), m_c(&g_c_00791610)
{
    init_00791610();
    if (flags & 1)
        atexit_fn_00791610(this);
}
