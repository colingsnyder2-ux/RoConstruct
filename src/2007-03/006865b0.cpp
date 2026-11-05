// from server: 100% by tester
struct CPropertyGridItemBrickColor {
    char pad[0x10];
    int field_0x10;
    bool sub_6711F0(int, int);
    int method();
};

int CPropertyGridItemBrickColor::method() {
    if (field_0x10 == 1) {
        if (sub_6711F0(4, 10))
            return 1;
    }
    return 0;
}
