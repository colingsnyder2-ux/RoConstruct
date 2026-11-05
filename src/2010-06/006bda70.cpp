// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006bda70;
extern void* g_b_006bda70;
extern void* g_c_006bda70;
extern "C" void atexit_fn_006bda70(void*);
struct X_006bda70 {
    X_006bda70(int flags);
    virtual void f_006bda70();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006bda70();
};
X_006bda70::X_006bda70(int flags) : m_a(&g_a_006bda70), m_b(&g_b_006bda70), m_c(&g_c_006bda70)
{
    init_006bda70();
    if (flags & 1)
        atexit_fn_006bda70(this);
}
