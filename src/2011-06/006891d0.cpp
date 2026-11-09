// from server: 79% by atomic.potato
struct S_func_006891d0 {
    char pad0[68];
    int m_44;
    void f();
};

struct S_func_00689280 {
    char pad0[144];
    char m_x;
    void f();
};

extern "C" int __cdecl func_0080b2ea(int, int, int, int, int);

void S_func_006891d0::f()
{
    int value = func_0080b2ea(0, 0xc071f8, 0xc59fa4, 0, m_44);
    if (value != 0)
        ((S_func_00689280*)value)->f();
}
