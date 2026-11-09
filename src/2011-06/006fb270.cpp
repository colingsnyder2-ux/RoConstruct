// from server: 75% by atomic.potato
extern "C" void __cdecl UpdateSetting(int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[176];
    int value;
    void set(int);
};

void VCRenderSettingsItem_EnumPropDescriptor::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        UpdateSetting(0xcd27dc);
    }
}
