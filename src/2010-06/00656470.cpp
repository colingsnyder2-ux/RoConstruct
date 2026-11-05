// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00656470;
extern void* g_b_00656470;
extern void* g_c_00656470;
extern "C" void atexit_fn_00656470(void*);
struct X_00656470 {
    X_00656470(int flags);
    virtual void f_00656470();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00656470();
};
X_00656470::X_00656470(int flags) : m_a(&g_a_00656470), m_b(&g_b_00656470), m_c(&g_c_00656470)
{
    init_00656470();
    if (flags & 1)
        atexit_fn_00656470(this);
}
