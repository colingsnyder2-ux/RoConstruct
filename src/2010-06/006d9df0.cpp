// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006d9df0;
extern void* g_b_006d9df0;
extern void* g_c_006d9df0;
extern "C" void atexit_fn_006d9df0(void*);
struct X_006d9df0 {
    X_006d9df0(int flags);
    virtual void f_006d9df0();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006d9df0();
};
X_006d9df0::X_006d9df0(int flags) : m_a(&g_a_006d9df0), m_b(&g_b_006d9df0), m_c(&g_c_006d9df0)
{
    init_006d9df0();
    if (flags & 1)
        atexit_fn_006d9df0(this);
}
