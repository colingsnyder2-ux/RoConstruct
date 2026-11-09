// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006f6a40;
extern void* g_b_006f6a40;
extern void* g_c_006f6a40;
extern "C" void atexit_fn_006f6a40(void*);
struct X_006f6a40 {
    X_006f6a40(int flags);
    virtual void f_006f6a40();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006f6a40();
};
X_006f6a40::X_006f6a40(int flags) : m_a(&g_a_006f6a40), m_b(&g_b_006f6a40), m_c(&g_c_006f6a40)
{
    init_006f6a40();
    if (flags & 1)
        atexit_fn_006f6a40(this);
}
