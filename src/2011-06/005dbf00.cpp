// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_005dbf00;
extern void* g_b_005dbf00;
extern void* g_c_005dbf00;
extern "C" void atexit_fn_005dbf00(void*);
struct X_005dbf00 {
    X_005dbf00(int flags);
    virtual void f_005dbf00();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_005dbf00();
};
X_005dbf00::X_005dbf00(int flags) : m_a(&g_a_005dbf00), m_b(&g_b_005dbf00), m_c(&g_c_005dbf00)
{
    init_005dbf00();
    if (flags & 1)
        atexit_fn_005dbf00(this);
}
