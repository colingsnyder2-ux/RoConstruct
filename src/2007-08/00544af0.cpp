// from server: 100% by colin
struct VDebugSettings {
    char pad[0xec];
    int field_ec;
    void setField(int);
};

void VDebugSettings::setField(int value)
{
    if (value != field_ec)
    {
        field_ec = value;
        extern void __stdcall func_00444710(int);
        func_00444710(0x8c1890);
    }
}
