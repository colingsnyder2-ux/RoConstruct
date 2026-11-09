// from server: 39% by Intel
struct std_string {
    char _pad[28];
    std_string(const std_string&);
};

extern "C" void __stdcall _SEH_prolog4(int, int);
extern "C" void __stdcall _SEH_epilog4();
extern "C" void __cdecl std_string_ctor_copy(std_string* thisptr, const std_string& src);

struct VStandardOut {
    char pad0[28];
    int field1C;
    std_string str20;
    std_string str3C;
    VStandardOut* __thiscall copy_construct(VStandardOut* src);
};

VStandardOut* __thiscall VStandardOut::copy_construct(VStandardOut* src) {
    _SEH_prolog4(-1, 0xACF465);
    VStandardOut* thisptr = this;
    std_string_ctor_copy(&thisptr->str20, src->str20);
    thisptr->field1C = src->field1C;
    std_string_ctor_copy(&thisptr->str3C, src->str3C);
    _SEH_epilog4();
    return thisptr;
}
