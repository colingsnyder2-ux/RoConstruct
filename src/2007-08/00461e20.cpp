// from server: 10% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_77DDAC();
extern "C" void __stdcall sub_77E6A4();
extern "C" void __stdcall sub_77E6D8();
extern "C" void __stdcall sub_77E690();
extern "C" void __stdcall sub_77E630();
extern "C" void __stdcall sub_77E62C();
extern "C" void __stdcall sub_77E5F8();
extern "C" void __stdcall sub_77D5A4();
extern "C" void __stdcall sub_77DD98();
extern "C" void __stdcall sub_77E6AC();
extern "C" void __stdcall sub_77DDBC();
extern "C" void __stdcall sub_77E61C();
extern "C" void __stdcall sub_77E6A8();

extern "C" void __cdecl sub_40D550();
extern "C" void __cdecl sub_40F8A0();
extern "C" void __cdecl sub_5595A0();
extern "C" void __cdecl sub_630A1E();

struct CSelectionCaption {
    void func();
};

void CSelectionCaption::func() {
    if (*(int*)((char*)this + 0x20) == 0)
        return;

    char buf1[16];
    char buf2[16];
    sub_77DDAC();
    sub_77E6A4();

    if (*(int*)((char*)this + 0x1b8) != 0) {
        int* p = *(int**)((char*)this + 0x1b8);
        int* q = *(int**)((char*)this + 0x1b0);
        int* r = *(int**)((char*)this + 0x1b4);
        if (r != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)r + 4), 1);
        }
        sub_40D550();
    }

    sub_77E6AC();
    sub_77DDBC();
}
