// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0058cb40;
extern void* g_b_0058cb40;
extern void* g_c_0058cb40;
extern "C" void atexit_fn_0058cb40(void*);
struct X_0058cb40 {
    X_0058cb40(int flags);
    virtual void f_0058cb40();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0058cb40();
};
X_0058cb40::X_0058cb40(int flags) : m_a(&g_a_0058cb40), m_b(&g_b_0058cb40), m_c(&g_c_0058cb40)
{
    init_0058cb40();
    if (flags & 1)
        atexit_fn_0058cb40(this);
}
