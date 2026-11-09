// from server: 100% by why2
struct ViewRbxGfx {
    char pad[0x2c];
    char field_2c;
    char pad2[0x34 - 0x2c - 1];
    char field_34;
    void func(char arg);
};

void ViewRbxGfx::func(char arg) {
    field_2c = 0;
    if (arg != 0) {
        field_34 = 0;
    }
}
