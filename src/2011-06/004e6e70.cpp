// from server: 19% by atomic.potato
extern "C" void __cdecl sub_773EE0();
extern "C" void __cdecl sub_4CB2E0();
extern "C" void __cdecl sub_4C9E40();
extern "C" void __cdecl sub_490470();
extern "C" void __cdecl sub_454A30();
extern "C" void __cdecl sub_4E5130();
extern "C" void __cdecl sub_5BA490();
extern "C" void __cdecl sub_80A05E();
extern "C" void __cdecl sub_4E6D00();
extern "C" void __cdecl sub_4AC3E0();
extern "C" void __cdecl sub_80A058();
extern "C" void __cdecl sub_A40534();
extern "C" void __cdecl sub_A40A50();

struct S {
    char pad0[0x10];
    char f10;
    char pad11[0x0c];
    void* f0c;
    void* f04;
    int f();
};

int S::f()
{
    f10 = 0;
    void* p = 0;
    sub_773EE0();
    *(char*)((char*)p + 0x31) = 1;
    *(void**)((char*)p + 4) = p;
    *(void**)p = p;
    *(void**)((char*)p + 8) = p;
    if (f0c != 0) {
        sub_4CB2E0();
        sub_4C9E40();
        if (*(void**)((char*)p + 0x18) != *(void**)((char*)p + 0x20)) {
            void* esi = 0;
            void* eax = *(void**)((char*)p + 0x18);
            if (eax != 0)
                esi = (char*)eax - 0x1c;
            sub_490470();
            if (*(void**)((char*)p + 0x14) != f04) {
                sub_A40534();
            }
            if (esi != f04) {
                void* v = *(void**)((char*)esi + 0x28);
                v = *(void**)((char*)v + 8);
                sub_A40A50();
                if (v) {
                    sub_454A30();
                }
            }
        }
    }
    sub_4E5130();
    sub_5BA490();
    sub_80A05E();
    sub_4E6D00();
    sub_4AC3E0();
    sub_80A058();
    return 0;
}
