// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005c2c20;
extern void* g_b_005c2c20;
extern void* g_c_005c2c20;
extern "C" void atexit_fn_005c2c20(void*);
struct X_005c2c20 {
    X_005c2c20(int flags);
    virtual void f_005c2c20();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005c2c20();
};
X_005c2c20::X_005c2c20(int flags) : m_a(&g_a_005c2c20), m_b(&g_b_005c2c20), m_c(&g_c_005c2c20)
{
    init_005c2c20();
    if (flags & 1)
        atexit_fn_005c2c20(this);
}
