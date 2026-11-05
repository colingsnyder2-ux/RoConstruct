// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006be7b0;
extern void* g_b_006be7b0;
extern void* g_c_006be7b0;
extern "C" void atexit_fn_006be7b0(void*);
struct X_006be7b0 {
    X_006be7b0(int flags);
    virtual void f_006be7b0();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006be7b0();
};
X_006be7b0::X_006be7b0(int flags) : m_a(&g_a_006be7b0), m_b(&g_b_006be7b0), m_c(&g_c_006be7b0)
{
    init_006be7b0();
    if (flags & 1)
        atexit_fn_006be7b0(this);
}
