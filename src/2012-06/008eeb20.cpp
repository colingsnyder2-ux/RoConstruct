// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_008eeb20;
extern void* g_b_008eeb20;
extern void* g_c_008eeb20;
extern "C" void atexit_fn_008eeb20(void*);
struct X_008eeb20 {
    X_008eeb20(int flags);
    virtual void f_008eeb20();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_008eeb20();
};
X_008eeb20::X_008eeb20(int flags) : m_a(&g_a_008eeb20), m_b(&g_b_008eeb20), m_c(&g_c_008eeb20)
{
    init_008eeb20();
    if (flags & 1)
        atexit_fn_008eeb20(this);
}
