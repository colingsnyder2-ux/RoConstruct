// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005a7a50;
extern void* g_b_005a7a50;
extern void* g_c_005a7a50;
extern "C" void atexit_fn_005a7a50(void*);
struct X_005a7a50 {
    X_005a7a50(int flags);
    virtual void f_005a7a50();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005a7a50();
};
X_005a7a50::X_005a7a50(int flags) : m_a(&g_a_005a7a50), m_b(&g_b_005a7a50), m_c(&g_c_005a7a50)
{
    init_005a7a50();
    if (flags & 1)
        atexit_fn_005a7a50(this);
}
