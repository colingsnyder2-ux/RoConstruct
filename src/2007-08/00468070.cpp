// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SharedPtr {
    void* px;
    void* pi;
};

struct Ofstream {
    char data[0x40];
};

extern "C" void __stdcall sub_77E5EC(int);
extern "C" void* __stdcall sub_77DD90(void*);
extern "C" void* __stdcall sub_77DD98(void*, int, int);
extern "C" void __stdcall sub_77E5F0(void*, void*);
extern "C" void __stdcall sub_77DDBC(void*);
extern "C" void __stdcall sub_77E628(void*);

extern "C" void __cdecl sub_62FF44();
extern "C" void __cdecl sub_62FF3E();
extern "C" void __cdecl sub_62FF38(int, int);
extern "C" void __cdecl sub_62FC62(void*);

extern "C" void __cdecl sub_40D550();
extern "C" void __cdecl sub_40F800();
extern "C" void __cdecl sub_5595A0();

struct VCWorkspace {
    void sub_467EE0(SharedPtr* out);
    void sub_468000(void* a, void* b);
    void sub_468070(void* a, void* b);
};

void VCWorkspace::sub_468070(void* a, void* b)
{
    Ofstream ofs;
    SharedPtr sp;
    void* p;

    sub_62FF44();
    sub_62FF3E();

    sub_77E5EC(1);

    p = sub_77DD90(a);
    p = sub_77DD98(p, 2, 0x40);
    sub_77E5F0(&ofs, p);

    sub_77DDBC(&sp);

    void* obj = b;
    SharedPtr local;
    local.px = *(void**)((char*)obj + 0x34);
    local.pi = *(void**)((char*)obj + 0x38);
    if (local.pi) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.pi + 4), 1);
    }

    sub_40D550();

    SharedPtr tmp;
    sub_467EE0(&tmp);
    void* v = *(void**)tmp.px;
    sub_468000(v, &local);

    if (sp.px) {
        sub_40F800();
        sub_62FC62(sp.px);
    }

    sub_5595A0();
    sub_77E628(&ofs);

    if (sp.px) {
        *(void**)((char*)sp.px + 4) = sp.pi;
    }
    if (sp.pi) {
        sub_62FF38(0, (int)sp.pi);
    }
}
