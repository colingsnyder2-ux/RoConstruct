// from server: 95% by atomic.potato
extern "C" int __cdecl sub_0080B2EA(int, int, int, int, int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[68];
    int value;
    int f();
};

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    int result = sub_0080B2EA(value, 0, 0xC071F8, 0xC57BD4, 0);
    if (result)
        return *(int *)(result + 0x94);
    return 0;
}
