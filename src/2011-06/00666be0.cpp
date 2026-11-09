// from server: 100% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[2];
    unsigned char enabled;
    unsigned char value;
    int f();
};

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    if (enabled)
        return 1;
    return value ? -1 : 0;
}
