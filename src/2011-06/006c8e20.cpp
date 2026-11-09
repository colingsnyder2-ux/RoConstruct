// from server: 61% by atomic.potato
struct S_func_006c8e20 {
    char pad0[0x220];
    int m_field220;
    void f(int);
};

extern "C" void __stdcall sub_00411f60();

void S_func_006c8e20::f(int a)
{
    if (m_field220 != a) {
        m_field220 = a;
        sub_00411f60();
        sub_00411f60();
    }
}
