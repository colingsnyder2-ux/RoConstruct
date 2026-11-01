// from server: 100% by atomic.potato
extern "C" int sub_84bee2();

struct CXTPCommandBar {
    char pad_00[0x20];
    int field_20;
    int func();
};

int CXTPCommandBar::func() {
    if (field_20 != 0 && (sub_84bee2() & 0x402000) != 0)
        return 1;
    return 0;
}
