// from server: 43% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad0[4];
    char pad1[0x14];
    unsigned int len;
    char pad2[4];
    char buf[4];
    int f();
};

extern "C" void __stdcall sub_401610(void*, void*);
extern "C" void* __cdecl sub_5d0f30();
extern "C" void* __cdecl sub_592e10(void*, void*);
extern "C" void __cdecl sub_5a8570(void*, void*);

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    char* p;
    if (len < 0x10)
        p = buf;
    else
        p = *(char**)buf;

    sub_401610((void*)0x5d0f90, (void*)0xcca364);
    void* a = sub_5d0f30();
    void* b = sub_592e10(a, p);
    sub_5a8570(a, b);
    return 0;
}
