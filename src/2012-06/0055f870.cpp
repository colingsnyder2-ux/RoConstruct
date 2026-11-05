// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0055f870;
extern void* g_b_0055f870;
extern void* g_c_0055f870;
extern "C" void atexit_fn_0055f870(void*);
struct X_0055f870 {
    X_0055f870(int flags);
    virtual void f_0055f870();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0055f870();
};
X_0055f870::X_0055f870(int flags) : m_a(&g_a_0055f870), m_b(&g_b_0055f870), m_c(&g_c_0055f870)
{
    init_0055f870();
    if (flags & 1)
        atexit_fn_0055f870(this);
}
