// from server: 36% by atomic.potato
struct S_func_008551c0 {
    char pad0[140];
    int m_x;
    int f();
};

int S_func_008551c0::f()
{
    return m_x;
}

struct S {
    void f();
};

extern "C" void __cdecl func_009266ac();
extern "C" void __cdecl func_008590d0(int);

void S::f()
{
    func_009266ac();
    S_func_008551c0* p = (S_func_008551c0*)this;
    p->f();
    func_008590d0(1);
}
