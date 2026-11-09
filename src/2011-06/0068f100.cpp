// from server: 100% by atomic.potato
struct GuiTextButton {
    char pad[0x340];
    int field_340;
    void sub_411f60(const char*);

    void setSomething(int value);
};

void GuiTextButton::setSomething(int value)
{
    if (field_340 != value) {
        field_340 = value;
        sub_411f60((const char*)0xccf4f0);
        sub_411f60((const char*)0xccf4b0);
    }
}
