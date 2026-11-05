// from server: 100% by colin
extern void __stdcall func_0052d780(int);

struct S_func_0044cf70 {
    char pad[0x1ac];
    char m_flag;
    void f();
};

void S_func_0044cf70::f()
{
    if (m_flag == 0)
        func_0052d780(1);
}
