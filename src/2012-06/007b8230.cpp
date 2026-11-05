// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_007b8230;
extern void* g_b_007b8230;
extern void* g_c_007b8230;
extern "C" void atexit_fn_007b8230(void*);
struct X_007b8230 {
    X_007b8230(int flags);
    virtual void f_007b8230();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_007b8230();
};
X_007b8230::X_007b8230(int flags) : m_a(&g_a_007b8230), m_b(&g_b_007b8230), m_c(&g_c_007b8230)
{
    init_007b8230();
    if (flags & 1)
        atexit_fn_007b8230(this);
}
