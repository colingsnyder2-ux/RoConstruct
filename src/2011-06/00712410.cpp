// from server: 76% by atomic.potato
struct S_func_00712410 {
    char pad0[0x28];
    int m_28;
    int m_2c;
    void f(int a, int b);
};

extern "C" void __stdcall sub_005976d0(int);

void S_func_00712410::f(int a, int b)
{
    char* p = (char*)a;
    if (p != 0)
        p -= 0x1c;
    else
        p = 0;
    int esi = m_2c;
    int edx = *(int*)(p + 0x94);
    edx = *(int*)(edx + esi);
    edx += m_28;
    sub_005976d0((int)(p + 0x94 + edx));
}
