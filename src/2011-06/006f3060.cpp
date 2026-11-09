// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_006f3060;
extern void* g_b_006f3060;
extern void* g_c_006f3060;
extern "C" void atexit_fn_006f3060(void*);
struct X_006f3060 {
    X_006f3060(int flags);
    virtual void f_006f3060();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_006f3060();
};
X_006f3060::X_006f3060(int flags) : m_a(&g_a_006f3060), m_b(&g_b_006f3060), m_c(&g_c_006f3060)
{
    init_006f3060();
    if (flags & 1)
        atexit_fn_006f3060(this);
}
