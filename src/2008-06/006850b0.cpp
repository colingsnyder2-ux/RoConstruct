// from server: 100% by colin
struct S_func_006850b0 {
    char pad0[0x54];
    int m_field54;
    char pad1[0x12c - 0x58];
    int m_array[1];
    void f(int a1, int a2);
};

void S_func_006850b0::f(int a1, int a2)
{
    if (a1 == 0) {
        m_field54 = a2;
    } else {
        *(int*)((char*)this + 0x12c + a1 * 4) = a2;
    }
}
