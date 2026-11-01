// from server: 71% by atomic.potato
struct S_func_00653c00 {
    int m_x;
    int f();
};

extern "C" int __cdecl sub_7f90e0(int, int, int, int, int, int, int);
extern "C" int __cdecl sub_653c00(int);

struct S_func_004dfed0 {
    char pad[0x108];
    int m_108;
    char pad2[0x10];
    int m_118;
    int m_11c;
    void sub_4dfe20(void*);
    void sub_598330();
    void f(void*);
};

void S_func_004dfed0::f(void* arg)
{
    if (*(char*)0xccc3b1 != 0) {
        sub_7f90e0(2, 0xa79a24, 0xa79a38, 0xab, 0, 0, 0);
    }
    void* p = (void*)0x4df780;
    sub_4dfe20(&p);
    sub_598330();
    if (m_108 != 0) {
        int a = sub_653c00(m_108);
        int* vt = (int*)*(int*)a;
        ((void (__thiscall*)(int, int, int, int, int, int))vt[0x84/4])(a, m_118, m_11c, 1, 0, 3);
        int b = sub_653c00(m_108);
        int* vt2 = (int*)*(int*)b;
        ((void (__thiscall*)(int, void*, int, int))vt2[0x38/4])(b, arg, 0, 3);
    }
}
