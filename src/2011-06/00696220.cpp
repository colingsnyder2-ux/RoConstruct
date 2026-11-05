// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00696220;
extern void* g_b_00696220;
extern void* g_c_00696220;
extern "C" void atexit_fn_00696220(void*);
struct X_00696220 {
    X_00696220(int flags);
    virtual void f_00696220();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00696220();
};
X_00696220::X_00696220(int flags) : m_a(&g_a_00696220), m_b(&g_b_00696220), m_c(&g_c_00696220)
{
    init_00696220();
    if (flags & 1)
        atexit_fn_00696220(this);
}
