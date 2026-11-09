// from server: 75% by atomic.potato
extern "C" void __cdecl S_func_00411f60(int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[316];
    int value;
    void setValue(int value);
};

void VCRenderSettingsItem_EnumPropDescriptor::setValue(int value)
{
    if (this->value != value)
    {
        this->value = value;
        S_func_00411f60(0x00ccdcc8);
    }
}
