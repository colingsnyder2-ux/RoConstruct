// from server: 76% by colin
struct CRobloxView {
    char pad[0x198];
    int field_0x198;
    void func_4566c0(int, int);
    void target();
};

void CRobloxView::target() {
    func_4566c0(field_0x198 == 0, 1);
}
