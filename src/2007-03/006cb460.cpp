// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_006c0000 {
    char pad[0x1b8];
    int field_1b8;
    int sub_6cb2c0();
    int sub_6cb460();
};

int seg_006c0000::sub_6cb460() {
    if (sub_6cb2c0() == 0)
        return 0;
    return field_1b8 == 0;
}
