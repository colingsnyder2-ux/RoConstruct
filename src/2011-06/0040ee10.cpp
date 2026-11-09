// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0040ee10;
extern void* g_b_0040ee10;
extern void* g_c_0040ee10;
extern "C" void atexit_fn_0040ee10(void*);
struct X_0040ee10 {
    X_0040ee10(int flags);
    virtual void f_0040ee10();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0040ee10();
};
X_0040ee10::X_0040ee10(int flags) : m_a(&g_a_0040ee10), m_b(&g_b_0040ee10), m_c(&g_c_0040ee10)
{
    init_0040ee10();
    if (flags & 1)
        atexit_fn_0040ee10(this);
}
