// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005dc870;
extern void* g_b_005dc870;
extern void* g_c_005dc870;
extern "C" void atexit_fn_005dc870(void*);
struct X_005dc870 {
    X_005dc870(int flags);
    virtual void f_005dc870();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005dc870();
};
X_005dc870::X_005dc870(int flags) : m_a(&g_a_005dc870), m_b(&g_b_005dc870), m_c(&g_c_005dc870)
{
    init_005dc870();
    if (flags & 1)
        atexit_fn_005dc870(this);
}
