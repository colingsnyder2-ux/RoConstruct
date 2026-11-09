// from server: 100% by atomic.potato
extern "C" void __stdcall NotifySettingChanged(int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    int pad[41];
    int value;
    void set(int);
};

void VCRenderSettingsItem_EnumPropDescriptor::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        NotifySettingChanged(0xCD2804);
    }
}
