// from server: 100% by atomic.potato
extern "C" void __stdcall Function_00411f60(void*);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    int pad[43];
    int value;
    void set(int value);
};

void VCRenderSettingsItem_EnumPropDescriptor::set(int value)
{
    if (this->value == value)
        return;
    this->value = value;
    Function_00411f60((void*)0x00cd2740);
}
