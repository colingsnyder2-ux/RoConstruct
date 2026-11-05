// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00666e80;
extern void* g_b_00666e80;
extern void* g_c_00666e80;
extern "C" void atexit_fn_00666e80(void*);
struct X_00666e80 {
    X_00666e80(int flags);
    virtual void f_00666e80();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00666e80();
};
X_00666e80::X_00666e80(int flags) : m_a(&g_a_00666e80), m_b(&g_b_00666e80), m_c(&g_c_00666e80)
{
    init_00666e80();
    if (flags & 1)
        atexit_fn_00666e80(this);
}
