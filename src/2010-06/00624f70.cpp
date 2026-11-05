// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00624f70;
extern void* g_b_00624f70;
extern void* g_c_00624f70;
extern "C" void atexit_fn_00624f70(void*);
struct X_00624f70 {
    X_00624f70(int flags);
    virtual void f_00624f70();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00624f70();
};
X_00624f70::X_00624f70(int flags) : m_a(&g_a_00624f70), m_b(&g_b_00624f70), m_c(&g_c_00624f70)
{
    init_00624f70();
    if (flags & 1)
        atexit_fn_00624f70(this);
}
