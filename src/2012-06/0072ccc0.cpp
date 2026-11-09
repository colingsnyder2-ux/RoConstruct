// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0072ccc0;
extern void* g_b_0072ccc0;
extern void* g_c_0072ccc0;
extern "C" void atexit_fn_0072ccc0(void*);
struct X_0072ccc0 {
    X_0072ccc0(int flags);
    virtual void f_0072ccc0();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0072ccc0();
};
X_0072ccc0::X_0072ccc0(int flags) : m_a(&g_a_0072ccc0), m_b(&g_b_0072ccc0), m_c(&g_c_0072ccc0)
{
    init_0072ccc0();
    if (flags & 1)
        atexit_fn_0072ccc0(this);
}
