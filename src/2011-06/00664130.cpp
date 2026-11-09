// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00664130;
extern void* g_b_00664130;
extern void* g_c_00664130;
extern "C" void atexit_fn_00664130(void*);
struct X_00664130 {
    X_00664130(int flags);
    virtual void f_00664130();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00664130();
};
X_00664130::X_00664130(int flags) : m_a(&g_a_00664130), m_b(&g_b_00664130), m_c(&g_c_00664130)
{
    init_00664130();
    if (flags & 1)
        atexit_fn_00664130(this);
}
