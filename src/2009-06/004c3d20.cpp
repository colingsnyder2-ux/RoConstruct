// from server: 100% by why2
struct S_func_004c3d20 {
    int m_x;
    void f();
};

extern "C" void __cdecl sub_0081b1d6();

void S_func_004c3d20::f()
{
    if (m_x == 0)
        return;
    sub_0081b1d6();
}
