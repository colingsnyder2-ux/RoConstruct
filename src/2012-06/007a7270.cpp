// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_007a7270;
extern void* g_b_007a7270;
extern void* g_c_007a7270;
extern "C" void atexit_fn_007a7270(void*);
struct X_007a7270 {
    X_007a7270(int flags);
    virtual void f_007a7270();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_007a7270();
};
X_007a7270::X_007a7270(int flags) : m_a(&g_a_007a7270), m_b(&g_b_007a7270), m_c(&g_c_007a7270)
{
    init_007a7270();
    if (flags & 1)
        atexit_fn_007a7270(this);
}
