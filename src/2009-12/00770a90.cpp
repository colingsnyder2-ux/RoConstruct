// from server: 76% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    int f();
    int field8;
    int fieldC;
};

extern "C" int __stdcall sub_0076ff80(int, int);

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    return sub_0076ff80(fieldC, field8);
}
