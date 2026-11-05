// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0077c7e0;
extern void* g_b_0077c7e0;
extern void* g_c_0077c7e0;
extern "C" void atexit_fn_0077c7e0(void*);
struct X_0077c7e0 {
    X_0077c7e0(int flags);
    virtual void f_0077c7e0();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0077c7e0();
};
X_0077c7e0::X_0077c7e0(int flags) : m_a(&g_a_0077c7e0), m_b(&g_b_0077c7e0), m_c(&g_c_0077c7e0)
{
    init_0077c7e0();
    if (flags & 1)
        atexit_fn_0077c7e0(this);
}
