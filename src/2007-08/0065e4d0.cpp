// from server: 100% by colin
// roc 2007-08 0065e4d0  unit: seg_00650000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0065e4d0
//
// 0065e4d0  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 0065e4d6  50                   push eax
// 0065e4d7  e8c4ffffff           call 0x65e4a0
// 0065e4dc  c3                   ret 

typedef unsigned long DWORD;

struct CXTPReportControl {
    char pad[0x90];
    DWORD field_90;

    void SomeMethod();
};

void __stdcall sub_65e4a0(DWORD);

void CXTPReportControl::SomeMethod() {
    sub_65e4a0(this->field_90);
}
