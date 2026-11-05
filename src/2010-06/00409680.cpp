// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00409680;
extern void* g_b_00409680;
extern void* g_c_00409680;
extern "C" void atexit_fn_00409680(void*);
struct X_00409680 {
    X_00409680(int flags);
    virtual void f_00409680();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00409680();
};
X_00409680::X_00409680(int flags) : m_a(&g_a_00409680), m_b(&g_b_00409680), m_c(&g_c_00409680)
{
    init_00409680();
    if (flags & 1)
        atexit_fn_00409680(this);
}
