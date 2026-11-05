// from server: 100% by why2
struct RBX_Assembly {
    char pad[0x64];
    unsigned char field_64;
    char pad2[0x78 - 0x65];
    unsigned char field_78;
    void func();
};

void RBX_Assembly::func() {
    field_64 = 1;
    field_78 = 0;
}
