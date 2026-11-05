// from server: 62% by atomic.potato
extern "C" int __cdecl Function_00410540(int);

struct VCRenderSettingsItem_EnumPropDescriptor
{
    int *vtable;
    int f(int, int);
};

int VCRenderSettingsItem_EnumPropDescriptor::f(int a, int b)
{
    int *v = vtable;
    return ((int (__thiscall *)(VCRenderSettingsItem_EnumPropDescriptor *, int, int))v[15])(this, b, Function_00410540(a));
}
