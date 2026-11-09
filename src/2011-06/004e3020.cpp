// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_004e3020;
extern void* g_b_004e3020;
extern void* g_c_004e3020;
extern "C" void atexit_fn_004e3020(void*);
struct X_004e3020 {
    X_004e3020(int flags);
    virtual void f_004e3020();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_004e3020();
};
X_004e3020::X_004e3020(int flags) : m_a(&g_a_004e3020), m_b(&g_b_004e3020), m_c(&g_c_004e3020)
{
    init_004e3020();
    if (flags & 1)
        atexit_fn_004e3020(this);
}
