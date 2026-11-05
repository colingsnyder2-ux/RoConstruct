// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0073b320;
extern void* g_b_0073b320;
extern void* g_c_0073b320;
extern "C" void atexit_fn_0073b320(void*);
struct X_0073b320 {
    X_0073b320(int flags);
    virtual void f_0073b320();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0073b320();
};
X_0073b320::X_0073b320(int flags) : m_a(&g_a_0073b320), m_b(&g_b_0073b320), m_c(&g_c_0073b320)
{
    init_0073b320();
    if (flags & 1)
        atexit_fn_0073b320(this);
}
