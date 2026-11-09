// from server: 82% by colin
struct ScreenGui {
    char pad[0x2c];
    int field_2c;
    char pad2[0xc];
    char field_3c;
    void sub_6e6ec0(int*);
    void func(int);
};

void ScreenGui::func(int arg) {
    if (field_3c) {
        sub_6e6ec0(&field_2c);
        field_3c = 0;
    }
}
