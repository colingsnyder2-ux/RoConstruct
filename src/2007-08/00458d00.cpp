// from server: 71% by colin
struct CRobloxWnd {
    void sub_458C00();
    void sub_63023E();
    void sub_463AF0();
    char pad[0x74];
    void* field_74;
    void func(int);
};

void CRobloxWnd::func(int) {
    sub_458C00();
    sub_63023E();
    if (field_74 != 0) {
        field_74 = 0;
        sub_463AF0();
    }
}
