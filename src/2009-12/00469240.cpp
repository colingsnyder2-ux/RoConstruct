// from server: 100% by atomic.potato
struct CRobloxWnd {
    char pad[0xb0];
    int field_b0;
    void sub_467db0(int);
    void sub_463950();
    void sub_462430();
    void sub_7f431c();
    void func();
};

void CRobloxWnd::func() {
    sub_467db0(0);
    if (field_b0 == 2) {
        sub_463950();
    } else {
        sub_462430();
    }
    sub_7f431c();
}
