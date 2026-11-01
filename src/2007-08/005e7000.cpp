// from server: 100% by colin
struct VFlag {
    char pad[0x240];
    int field240;
    void set(int value);
};

extern "C" void __stdcall sub_444710(int);

void VFlag::set(int value) {
    field240 = value;
    sub_444710(0x008c6f34);
}
