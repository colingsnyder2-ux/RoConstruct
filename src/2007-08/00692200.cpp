// from server: 100% by colin
struct CXTPStatusBarPane
{
    char pad_00[0x50];
    int field_50;
    char pad_54[0x08];
    int field_5c;
    int field_60;
    int getValue();
};

int CXTPStatusBarPane::getValue()
{
    if (field_60 == 0)
        return field_50 + 0xac;
    return (int)((char*)this + 0x5c);
}
