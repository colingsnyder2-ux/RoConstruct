// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_0040f370;
extern void* g_b_0040f370;
extern void* g_c_0040f370;
extern "C" void atexit_fn_0040f370(void*);
struct X_0040f370 {
    X_0040f370(int flags);
    virtual void f_0040f370();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_0040f370();
};
X_0040f370::X_0040f370(int flags) : m_a(&g_a_0040f370), m_b(&g_b_0040f370), m_c(&g_c_0040f370)
{
    init_0040f370();
    if (flags & 1)
        atexit_fn_0040f370(this);
}
