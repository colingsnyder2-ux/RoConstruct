// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00714a00;
extern void* g_b_00714a00;
extern void* g_c_00714a00;
extern "C" void atexit_fn_00714a00(void*);
struct X_00714a00 {
    X_00714a00(int flags);
    virtual void f_00714a00();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00714a00();
};
X_00714a00::X_00714a00(int flags) : m_a(&g_a_00714a00), m_b(&g_b_00714a00), m_c(&g_c_00714a00)
{
    init_00714a00();
    if (flags & 1)
        atexit_fn_00714a00(this);
}
