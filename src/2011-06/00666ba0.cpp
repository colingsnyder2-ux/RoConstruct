// from server: 100% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad0[148];
    int value;
    char pad1[2];
    unsigned char flag;
    int f();
};

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    if (value == 3 && flag == 0)
        return 1;
    return 0;
}
