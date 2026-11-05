// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0065e160;
extern void* g_b_0065e160;
extern void* g_c_0065e160;
extern "C" void atexit_fn_0065e160(void*);
struct X_0065e160 {
    X_0065e160(int flags);
    virtual void f_0065e160();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0065e160();
};
X_0065e160::X_0065e160(int flags) : m_a(&g_a_0065e160), m_b(&g_b_0065e160), m_c(&g_c_0065e160)
{
    init_0065e160();
    if (flags & 1)
        atexit_fn_0065e160(this);
}
