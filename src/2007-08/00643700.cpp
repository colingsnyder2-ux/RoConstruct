// from server: 100% by colin
struct CXTPCommandBarCmdUI {
    char pad[0x28];
    void* field_28;
    int field_2c;
    void SetCheck(int nCheck);
};

void CXTPCommandBarCmdUI::SetCheck(int nCheck) {
    field_2c = 1;
    void* p = field_28;
    if (*(int*)((char*)p + 0xa0) != nCheck) {
        *(int*)((char*)p + 0xa0) = nCheck;
        nCheck = 1;
        extern void __stdcall sub_63A690(int);
        sub_63A690(nCheck);
    }
}
