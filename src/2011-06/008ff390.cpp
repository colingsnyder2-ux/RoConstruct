// from server: 25% by atomic.potato
struct S_func_0088f280 {
    char pad0[1480];
    int m_x;
    int f();
};

int S_func_0088f280::f()
{
    return m_x;
}

extern "C" void __stdcall func_a42e00();
extern "C" void __stdcall func_0080f7e0();
extern "C" void __stdcall func_0085d1a0();

struct CXTPRibbonControlSystemPopupBarListCaption {
    void f(int);
};

void CXTPRibbonControlSystemPopupBarListCaption::f(int)
{
    func_a42e00();
    S_func_0088f280 *p = (S_func_0088f280 *)this;
    int v = p->f();
    func_0080f7e0();
    func_a42e00();
    func_a42e00();
    p->f();
    func_0080f7e0();
    func_0085d1a0();
}
