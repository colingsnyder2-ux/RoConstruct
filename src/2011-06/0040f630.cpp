// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0040f630;
extern void* g_b_0040f630;
extern void* g_c_0040f630;
extern "C" void atexit_fn_0040f630(void*);
struct X_0040f630 {
    X_0040f630(int flags);
    virtual void f_0040f630();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0040f630();
};
X_0040f630::X_0040f630(int flags) : m_a(&g_a_0040f630), m_b(&g_b_0040f630), m_c(&g_c_0040f630)
{
    init_0040f630();
    if (flags & 1)
        atexit_fn_0040f630(this);
}
