// from server: 100% by colin
extern "C" void* (__thiscall *sub_80244c)(void*, const char*);
extern "C" void sub_49eb30();
extern "C" void sub_49eba0();
extern "C" void sub_491360();
extern "C" void sub_49a8a0();
extern "C" void sub_49ec10();
extern "C" void sub_49ec80();
extern "C" void sub_49e890();

struct S {
};

void __cdecl f(const char* s) {
    sub_80244c((void*)0x970b88, s);
    sub_49eb30();
    sub_49eba0();
    sub_491360();
    sub_49a8a0();
    sub_49ec10();
    sub_49ec80();
    sub_49e890();
}
