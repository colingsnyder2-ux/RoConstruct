// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of BoundProp modeled as a file-local struct; object at 0x9746e0,
// pointer member at +0x18 (0x9746f8), vtable pointer at +0.
struct FakeBoundProp {
    const void* vtable;
    char pad[0x14];
    void* ptr;
};

extern FakeBoundProp prop_SkyRt_obj;
extern const char g_vtable_0080b730[];

extern "C" void fn_007fcd10(void);

#pragma comment(linker, "/alternatename:fn_007fcd10=??__F?prop_SkyRt@Sky@RBX@@2V?$BoundProp@VTextureId@RBX@@$00@Reflection@2@A@@YAXXZ")

extern "C" void fn_007fcd10(void)
{
    if (prop_SkyRt_obj.ptr)
        operator delete(prop_SkyRt_obj.ptr);
    prop_SkyRt_obj.vtable = g_vtable_0080b730;
}
