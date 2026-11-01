// from server: 100% by tester
struct CRobloxView {
    char pad[0x1d8];
    void* field_198;
    int sub_4562E0();
    int sub_4567D0(int, int);
};

int CRobloxView::sub_4567D0(int, int) {
    if (field_198) {
        (*(void (__thiscall**)(void*))(*(int*)field_198 + 0x68))(field_198);
        field_198 = 0;
        sub_4562E0();
    }
    return 0;
}
