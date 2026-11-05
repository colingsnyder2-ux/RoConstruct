// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0059e620;
extern void* g_b_0059e620;
extern void* g_c_0059e620;
extern "C" void atexit_fn_0059e620(void*);
struct X_0059e620 {
    X_0059e620(int flags);
    virtual void f_0059e620();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0059e620();
};
X_0059e620::X_0059e620(int flags) : m_a(&g_a_0059e620), m_b(&g_b_0059e620), m_c(&g_c_0059e620)
{
    init_0059e620();
    if (flags & 1)
        atexit_fn_0059e620(this);
}
