// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00677d90;
extern void* g_b_00677d90;
extern void* g_c_00677d90;
extern "C" void atexit_fn_00677d90(void*);
struct X_00677d90 {
    X_00677d90(int flags);
    virtual void f_00677d90();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00677d90();
};
X_00677d90::X_00677d90(int flags) : m_a(&g_a_00677d90), m_b(&g_b_00677d90), m_c(&g_c_00677d90)
{
    init_00677d90();
    if (flags & 1)
        atexit_fn_00677d90(this);
}
