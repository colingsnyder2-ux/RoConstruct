// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_00762e60;
extern void* g_b_00762e60;
extern void* g_c_00762e60;
extern "C" void atexit_fn_00762e60(void*);
struct X_00762e60 {
    X_00762e60(int flags);
    virtual void f_00762e60();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_00762e60();
};
X_00762e60::X_00762e60(int flags) : m_a(&g_a_00762e60), m_b(&g_b_00762e60), m_c(&g_c_00762e60)
{
    init_00762e60();
    if (flags & 1)
        atexit_fn_00762e60(this);
}
