// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00792310;
extern void* g_b_00792310;
extern void* g_c_00792310;
extern "C" void atexit_fn_00792310(void*);
struct X_00792310 {
    X_00792310(int flags);
    virtual void f_00792310();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00792310();
};
X_00792310::X_00792310(int flags) : m_a(&g_a_00792310), m_b(&g_b_00792310), m_c(&g_c_00792310)
{
    init_00792310();
    if (flags & 1)
        atexit_fn_00792310(this);
}
