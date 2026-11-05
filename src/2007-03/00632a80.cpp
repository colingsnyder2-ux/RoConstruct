// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_00630000 {
    char pad[0x74];
    int field_74;
    int field_78;
    int get(int* p);
};

int seg_00630000::get(int* p) {
    if (p[0x3c] == 0)
        return field_78;
    return field_74;
}
