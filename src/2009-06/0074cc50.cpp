// from server: 100% by why2
// roc 2009-06 0074cc50  unit: CXTPReportControl  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0074cc50
//
// 0074cc50  8b8194000000         mov eax, dword ptr [ecx + 0x94]
// 0074cc56  50                   push eax
// 0074cc57  e8c4ffffff           call 0x74cc20
// 0074cc5c  c3                   ret

struct CXTPReportControl {
    char pad[0x94];
    int field_94;
    void sub_74cc20(int);
    void func();
};

void CXTPReportControl::func() {
    sub_74cc20(field_94);
}
