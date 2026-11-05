// from server: 50% by atomic.potato
extern "C" int __cdecl Call_005d06e0();

struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad0[36];
    int value;

    VCRenderSettingsItem_EnumPropDescriptor *f(int a, int b, int c, int d, int e, int f, int g);
};

VCRenderSettingsItem_EnumPropDescriptor *
VCRenderSettingsItem_EnumPropDescriptor::f(int a, int b, int c, int d, int e, int f, int g)
{
    value = Call_005d06e0();
    return this;
}
