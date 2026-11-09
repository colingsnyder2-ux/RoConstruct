// from server: 28% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_00598990();
extern "C" void* __cdecl sub_005CABE0();

struct S {
    void* v0;
    void* v1;
    char pad[0x10];
    void* v18;
    void* v1c;
    void* v20;
    S();
};

S::S()
{
    sub_00598990();
    v0 = (void*)0xA9587C;
    v1 = (void*)0xA95874;
    v18 = (void*)0xA95868;
    v1c = (void*)0xA9585C;
    v20 = sub_005CABE0();
    ++*(DWORD*)0xCCA9A8;
}
