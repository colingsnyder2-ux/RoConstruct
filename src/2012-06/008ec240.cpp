// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_008ec240;
extern void* g_b_008ec240;
extern void* g_c_008ec240;
extern "C" void atexit_fn_008ec240(void*);
struct X_008ec240 {
    X_008ec240(int flags);
    virtual void f_008ec240();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_008ec240();
};
X_008ec240::X_008ec240(int flags) : m_a(&g_a_008ec240), m_b(&g_b_008ec240), m_c(&g_c_008ec240)
{
    init_008ec240();
    if (flags & 1)
        atexit_fn_008ec240(this);
}
