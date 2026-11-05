// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_007acc50;
extern void* g_b_007acc50;
extern void* g_c_007acc50;
extern "C" void atexit_fn_007acc50(void*);
struct X_007acc50 {
    X_007acc50(int flags);
    virtual void f_007acc50();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_007acc50();
};
X_007acc50::X_007acc50(int flags) : m_a(&g_a_007acc50), m_b(&g_b_007acc50), m_c(&g_c_007acc50)
{
    init_007acc50();
    if (flags & 1)
        atexit_fn_007acc50(this);
}
