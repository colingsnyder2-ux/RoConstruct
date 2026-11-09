// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0060be60;
extern void* g_b_0060be60;
extern void* g_c_0060be60;
extern "C" void atexit_fn_0060be60(void*);
struct X_0060be60 {
    X_0060be60(int flags);
    virtual void f_0060be60();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0060be60();
};
X_0060be60::X_0060be60(int flags) : m_a(&g_a_0060be60), m_b(&g_b_0060be60), m_c(&g_c_0060be60)
{
    init_0060be60();
    if (flags & 1)
        atexit_fn_0060be60(this);
}
