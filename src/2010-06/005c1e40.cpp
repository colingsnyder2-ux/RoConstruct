// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005c1e40;
extern void* g_b_005c1e40;
extern void* g_c_005c1e40;
extern "C" void atexit_fn_005c1e40(void*);
struct X_005c1e40 {
    X_005c1e40(int flags);
    virtual void f_005c1e40();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005c1e40();
};
X_005c1e40::X_005c1e40(int flags) : m_a(&g_a_005c1e40), m_b(&g_b_005c1e40), m_c(&g_c_005c1e40)
{
    init_005c1e40();
    if (flags & 1)
        atexit_fn_005c1e40(this);
}
