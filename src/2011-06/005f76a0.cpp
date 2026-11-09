// from server: 33% by atomic.potato
extern "C" int __stdcall Function_005d0e50();

struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[36];
    int value;
    int f();
};

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    value = Function_005d0e50();
    return 0;
}
