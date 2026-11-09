// from server: 29% by colin
struct S_func_0062a880 {
    char pad0[4];
    int* m_p4;
    int m_8;
    void f();
};

extern "C" int __cdecl sub_004D1C00();
extern "C" int __cdecl sub_00408740(int, int);
extern "C" void __cdecl sub_005491A0();
extern "C" void __cdecl sub_0061C680(int, int, int, int, int, int);
extern "C" void __cdecl sub_00624110(int, int);
extern "C" void __cdecl sub_006247D0(int);
extern "C" void __cdecl sub_0062A230();

extern "C" void __stdcall sub_77E698(int);
extern "C" void __stdcall sub_77E6AC();
extern "C" void __stdcall sub_77E658(int, int, int, int);
extern "C" void __stdcall sub_77E6A4();
extern "C" int __stdcall sub_77E42C(int, int, int);
extern "C" void __stdcall sub_77E43C();
extern "C" void __stdcall sub_77E440();
extern "C" void __stdcall sub_77E460();
extern "C" void __stdcall sub_77E5E0(int);
extern "C" void __stdcall sub_77E5E4(int);
extern "C" void __stdcall sub_77E6D8();
extern "C" void __stdcall sub_77E4FC(int);
extern "C" void __stdcall sub_77E430(int);
extern "C" void __stdcall sub_77E65C(int);

void S_func_0062a880::f()
{
    int* p = (int*)sub_004D1C00();
    m_p4 = p;
    *(char*)((char*)p + 0x29) = 1;
    p[1] = (int)p;
    p[0] = (int)p;
    p[2] = (int)p;
    m_8 = 0;

    char buf1[0x40];
    char buf2[0x40];
    char buf3[0x40];
    char buf4[0x40];

    sub_77E698((int)"Fonts\\diogenes.fnt");
    sub_00408740((int)buf1, (int)buf2);
    sub_005491A0();
    sub_77E6AC();
    sub_77E658((int)buf3, (int)buf1, 0x40, 1);
    sub_77E6A4();
    sub_77E42C((int)buf4, (int)buf3, 10);

    while (1) {
        int q = sub_77E42C((int)buf4, (int)buf3, 10);
        int* r = (int*)(*(int*)(q + 4));
        int v = *(int*)((char*)r + q + 8);
        r = (int*)((char*)r + q);
        if (((v & 6) == 0)) break;

        sub_77E43C();
        sub_77E440();
        sub_77E460();
        sub_77E5E0((int)buf1);
        sub_77E5E4((int)buf2);
        sub_77E5E0((int)buf3);
        sub_77E5E0((int)buf4);
        sub_77E6D8();
        sub_0061C680((int)buf1, (int)buf2, (int)buf3, (int)buf4, (int)this, 0);
        sub_77E4FC((int)buf1);
        sub_77E43C();
        sub_77E440();
        sub_77E460();
        sub_00624110((int)buf1, (int)buf2);
        sub_006247D0((int)buf3);
        sub_77E4FC((int)buf1);
        sub_0062A230();
    }

    sub_77E430((int)buf1);
    sub_77E6AC();
    sub_77E65C((int)buf1);
    sub_77E6AC();
}
