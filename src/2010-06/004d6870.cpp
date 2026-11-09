// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_004d6870;
extern void* g_b_004d6870;
extern void* g_c_004d6870;
extern "C" void atexit_fn_004d6870(void*);
struct X_004d6870 {
    X_004d6870(int flags);
    virtual void f_004d6870();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_004d6870();
};
X_004d6870::X_004d6870(int flags) : m_a(&g_a_004d6870), m_b(&g_b_004d6870), m_c(&g_c_004d6870)
{
    init_004d6870();
    if (flags & 1)
        atexit_fn_004d6870(this);
}
