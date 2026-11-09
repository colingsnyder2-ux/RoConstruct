// from server: 95% by atomic.potato
struct S_func_006e3040 {
    char pad0[0x20];
    char pad1[0x78];
    S_func_006e3040* f(int);
};

extern "C" void __stdcall sub_00773a20();
extern "C" void __cdecl sub_007f385a(void*);

S_func_006e3040* S_func_006e3040::f(int)
{
    *(int*)((char*)this + 0x00) = 0x9dab24;
    *(int*)((char*)this + 0x20) = 0x9dab08;
    *(int*)((char*)this + 0x98) = 0x9daaec;
    sub_00773a20();
    if ((*(unsigned char*)((char*)this + 8) & 1) != 0) {
        sub_007f385a(this);
    }
    return this;
}
