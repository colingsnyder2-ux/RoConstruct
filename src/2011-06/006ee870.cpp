// from server: 24% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_005BA570();
extern "C" void __cdecl sub_005A1230();
extern "C" void __cdecl sub_0064FCE0();
extern "C" void __cdecl sub_00678980();
extern "C" void __cdecl sub_006EE700();
extern "C" void __cdecl sub_00592CE0();

extern "C" int __stdcall sub_00A40A50();
extern "C" void __stdcall sub_00A404D0();

extern DWORD g_00CCA554;
extern DWORD g_00CCAA2C;

struct S {
    void* f0;
    void* f4;
    void method();
};

void S::method()
{
    if (sub_00A40A50()) {
        void* a = f4;
        void* b;
        sub_005A1230();
        sub_0064FCE0();
        sub_00592CE0();
        sub_00678980();
        sub_00A404D0();
        sub_00A404D0();
        ++g_00CCA554;
        ++g_00CCAA2C;
        sub_005BA570();
        f0 = (void*)0;
    }
    sub_006EE700();
}
