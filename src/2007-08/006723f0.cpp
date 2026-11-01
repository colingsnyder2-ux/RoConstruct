// from server: 100% by colin
struct CXTPControlButtonColor {
    char pad[0x168];
    int field_168;
    void sub_6ca540(int, int);
    void sub_6723f0(int, int);
};

void CXTPControlButtonColor::sub_6723f0(int a, int b) {
    sub_6ca540(a, b);
    field_168 = *(int*)((char*)a + 0x168);
}
