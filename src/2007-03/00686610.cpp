// from server: 100% by tester
struct CPropertyGridItemBrickColor {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    bool check(int a, int b);
    int method();
};

int CPropertyGridItemBrickColor::method() {
    if (field10 == 2) {
        if (check(5, 1)) {
            return 1;
        }
    }
    return 0;
}
