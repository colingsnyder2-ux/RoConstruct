// from server: 32% by atomic.potato
struct S_func_00665be0 {
    char pad0[0x18];
    int m_field18;
    int m_field1c;
    int m_field20;
    void f(int, int, int, int, int, int, int, int, int);
};

extern "C" int __cdecl sub_00401710(int, int);
extern "C" int __cdecl sub_005ea8e0();
extern "C" int __cdecl sub_005eeec0();
extern "C" void __cdecl sub_005f8830();
extern "C" int __cdecl sub_00665a10(int*);
extern "C" void __cdecl sub_00718a32(int);

void S_func_00665be0::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    sub_00401710(0xa4a4a4, 0x5eef20);
    int v = sub_005eeec0();
    sub_005ea8e0();
    sub_005f8830();
    m_field18 = v;
    int t1 = a1;
    int t2 = a2;
    int t3 = a3;
    int t4 = a4;
    int t5 = a5;
    int t6 = a6;
    int t7 = a7;
    int t8 = a8;
    int t9 = a9;
    int tmp = 0;
    *(int*)this = 0x8e29b4;
    sub_00665a10(&tmp);
    m_field1c = tmp;
    sub_00718a32(t9);
    sub_00401710(0xa4a4a4, 0x5eef20);
    m_field20 = sub_005eeec0();
}
