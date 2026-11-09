// from server: 60% by atomic.potato
struct S_func_008114d0 {
    char pad0[236];
    int m_x;
    void f(int a1);
};

void S_func_008114d0::f(int a1)
{
    m_x = (int)a1;
}

extern "C" int __cdecl func_00815470(int a1, int a2, int a3);

int __cdecl func_00427e60(int a1, int a2, int a3)
{
    int result = func_00815470(a1, a2, a3);
    if (a2 == 0x8040)
    {
        ((S_func_008114d0*)result)->f(0x10);
        return result;
    }
    return result;
}
