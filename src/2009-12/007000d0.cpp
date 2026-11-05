// from server: 30% by atomic.potato
struct VTeamsBoundFuncDesc {
    void* vtbl0;
    void* vtbl4;
    char pad08[0x10];
    void* vtbl18;
    void* vtbl1c;
    char pad20[0x74];
    char flag94;
    char pad95[3];
    char field98[0x40];
    void* ctor();
};

extern "C" void __stdcall sub_6ffea0();
extern "C" void* __cdecl sub_7f3860(int);
extern "C" void __stdcall sub_51ca20(void*, void*);
extern "C" void __stdcall sub_75e660(void*);
extern "C" void __stdcall sub_636ac0(void*, void*);
extern "C" void* __stdcall sub_98b6f4(const char*);
extern "C" void __stdcall sub_98b6e4(void*);

void* VTeamsBoundFuncDesc::ctor()
{
    sub_6ffea0();
    flag94 = 1;
    vtbl0 = (void*)0x9ddcb4;
    vtbl4 = (void*)0x9ddca8;
    vtbl18 = (void*)0x9ddc9c;
    vtbl1c = (void*)0x9ddc94;
    void* p = sub_7f3860(4);
    if (p) {
        *(void**)p = &p;
    } else {
        p = 0;
    }
    void* local = p;
    void* local2 = 0;
    void* local3 = 0;
    void* local4 = 0;
    sub_51ca20(field98, &local);
    sub_75e660(&local);
    void* s = sub_98b6f4((const char*)0x9ddc18);
    sub_636ac0(this, &s);
    sub_98b6e4(&s);

    return this;
}
