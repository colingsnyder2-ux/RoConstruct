// from server: 100% by intel
struct GuiTextButton {
    char pad[0x35c];
    int field_360;
    void sub_414da0(const void*);
    void set(int);
};

void GuiTextButton::set(int value)
{
    if (field_360 != value) {
        field_360 = value;
        sub_414da0((const void*)0xe34740);
        sub_414da0((const void*)0xe346b4);
        sub_414da0((const void*)0xe34600);
    }
}
