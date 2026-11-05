// from server: 57% by atomic.potato
struct GuiTextButton {
    char pad[0x360];
    int field_360;
    void setSomething(int);
};

extern "C" void __cdecl sub_411f60(const char*);

void GuiTextButton::setSomething(int value)
{
    if (field_360 != value) {
        sub_411f60((const char*)0xccf3dc);
        field_360 = value;
        sub_411f60((const char*)0xccf4b0);
    }
}
