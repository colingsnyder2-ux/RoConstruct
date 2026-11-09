// from server: 100% by colin
struct HopperBin {
    char pad[0x158];
    int field_158;
    unsigned char field_15c;
    void sub_59e690();
    void sub_59e790();
    void func();
};

void HopperBin::func() {
    if (field_15c == 0) {
        field_15c = 1;
        if (field_158 == 0) {
            sub_59e690();
        } else {
            sub_59e790();
        }
    } else {
        void (HopperBin::*p)() = *(void (HopperBin::**)())(*(void***)this + 0x8c / 4);
        (this->*p)();
    }
}
