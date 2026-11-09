// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00411f20;
extern void* g_b_00411f20;
extern void* g_c_00411f20;
extern "C" void atexit_fn_00411f20(void*);
struct X_00411f20 {
    X_00411f20(int flags);
    virtual void f_00411f20();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00411f20();
};
X_00411f20::X_00411f20(int flags) : m_a(&g_a_00411f20), m_b(&g_b_00411f20), m_c(&g_c_00411f20)
{
    init_00411f20();
    if (flags & 1)
        atexit_fn_00411f20(this);
}
