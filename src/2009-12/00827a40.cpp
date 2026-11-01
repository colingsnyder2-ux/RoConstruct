// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct CXTPReportControl {
    char pad[0x94];
    int field_94;
    void sub_74cc20(int);
    void func();
};

void CXTPReportControl::func() {
    sub_74cc20(field_94);
}