// from server: 28% by atomic.potato
struct S_func_00753590 {
    char pad0[0x1c];
    int m_field1c;
    int m_field20;
    int f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

extern "C" int __cdecl sub_0067EAF0();
extern "C" int __cdecl sub_006512F0();
extern "C" int __cdecl sub_00662B90(int, int, int, int, int, int);
extern "C" int __cdecl sub_00753380(int, int, int, int, int);
extern "C" int __cdecl sub_007F385A(int);

int S_func_00753590::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int v1 = sub_0067EAF0();
    int v2 = sub_006512F0();
    sub_00662B90(v2, v1, a1, a2, a3, a4);
    int* p = (int*)sub_00753380(a5, a6, a7, a8, (int)&m_field20);
    int v3 = *p;
    *p = 0;
    m_field20 = v3;
    sub_007F385A(a8);
    m_field1c = 0x9e4844;
    *(int*)this = 0x9e484c;
    return (int)this;
}
