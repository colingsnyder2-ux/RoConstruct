// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00730130;
extern void* g_b_00730130;
extern void* g_c_00730130;
extern "C" void atexit_fn_00730130(void*);
struct X_00730130 {
    X_00730130(int flags);
    virtual void f_00730130();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00730130();
};
X_00730130::X_00730130(int flags) : m_a(&g_a_00730130), m_b(&g_b_00730130), m_c(&g_c_00730130)
{
    init_00730130();
    if (flags & 1)
        atexit_fn_00730130(this);
}
