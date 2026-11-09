// from server: 57% by atomic.potato
struct S_func_006c8e50 {
    char pad0[0x240];
    int m_field240;
    void f(int);
};

extern "C" void __cdecl sub_00411f60(int);

void S_func_006c8e50::f(int a)
{
    if (m_field240 != a) {
        sub_00411f60(0xcd0e98);
        m_field240 = a;
        sub_00411f60(0xcd0f6c);
    }
}
