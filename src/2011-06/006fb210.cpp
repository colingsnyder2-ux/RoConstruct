// from server: 72% by atomic.potato
extern "C" void __stdcall NotifyChange(void *, unsigned int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    int pad[42];
    int value;
    void set(int);
};

void VCRenderSettingsItem_EnumPropDescriptor::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        NotifyChange(this, 0x00cd2768);
    }
}
