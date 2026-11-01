// from server: 34% by Intel
struct VAnimationTrack {
    char pad_0x94[0x94];
    struct BoundFuncDesc {
        char pad_0x0[0x10];
    } boundFuncDesc;
};

extern "C" void __stdcall __security_cookie_init(int, int);
extern "C" void __stdcall std_string_ctor(void*, const void*);
extern "C" void __stdcall std_string_dtor(void*);
extern "C" void __cdecl sub_539770(void*);

int __stdcall VAnimationTrack_BoundFuncDesc_ctor(VAnimationTrack::BoundFuncDesc* thisptr, int a2, int a3, int a4, int a5, int a6, int a7) {
    __security_cookie_init(-1, 0xABE719);
    char localString[0x1C];
    *(int*)localString = 0;
    std_string_ctor(localString, &a7);
    sub_539770(&thisptr->pad_0x0);
    std_string_dtor(localString);
    return 0;
}
