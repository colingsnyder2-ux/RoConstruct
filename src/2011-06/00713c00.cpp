// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00713c00;
extern void* g_b_00713c00;
extern void* g_c_00713c00;
extern "C" void atexit_fn_00713c00(void*);
struct X_00713c00 {
    X_00713c00(int flags);
    virtual void f_00713c00();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00713c00();
};
X_00713c00::X_00713c00(int flags) : m_a(&g_a_00713c00), m_b(&g_b_00713c00), m_c(&g_c_00713c00)
{
    init_00713c00();
    if (flags & 1)
        atexit_fn_00713c00(this);
}
