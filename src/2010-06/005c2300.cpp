// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005c2300;
extern void* g_b_005c2300;
extern void* g_c_005c2300;
extern "C" void atexit_fn_005c2300(void*);
struct X_005c2300 {
    X_005c2300(int flags);
    virtual void f_005c2300();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005c2300();
};
X_005c2300::X_005c2300(int flags) : m_a(&g_a_005c2300), m_b(&g_b_005c2300), m_c(&g_c_005c2300)
{
    init_005c2300();
    if (flags & 1)
        atexit_fn_005c2300(this);
}
