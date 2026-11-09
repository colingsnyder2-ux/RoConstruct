// from server: 100% by tester
struct EventDesc {
    char pad[0xb8];
    int field_b8;
    void set(int value);
};

void EventDesc::set(int value) {
    if (field_b8 != value) {
        field_b8 = value;
        extern void __stdcall sub_414da0(int);
        sub_414da0(0xe373f4);
    }
}
