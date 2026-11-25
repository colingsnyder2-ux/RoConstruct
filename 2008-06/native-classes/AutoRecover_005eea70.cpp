// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083fe40[];
extern "C" char g_008402a4[];
extern "C" char g_0097b11c[];

// INFERRED: layout from the disassembly; PropertyDescriptor header is 0x18 bytes, then type at +0x18 and binding at +0x1c.
struct Local_005eea70 {
    unsigned int vtable;
    unsigned int pad[5];
    void* type;
    void* binding;
};

struct Local_005eea70_Binding {
    unsigned int vtable;
    unsigned int getter;
    unsigned int setter;
};

extern "C" void fn_00557330(void (*fn)(), void* flag);
extern "C" void fn_005ed620();
extern "C" void* fn_005ed5c0();
extern "C" void* fn_0059c7f0();
extern "C" void __fastcall fn_0056c650(Local_005eea70* self, int unusedEdx,
                                       void* owner, void* type,
                                       unsigned int a, unsigned int b,
                                       unsigned int flags);
extern "C" int fn_006a0920(int a1);

extern "C" Local_005eea70* __fastcall fn_005eea70(Local_005eea70* self, int unusedEdx,
                                                  unsigned int a, unsigned int b,
                                                  unsigned int getter, unsigned int setter,
                                                  unsigned int flags)
{
    fn_00557330(fn_005ed620, reinterpret_cast<void*>(g_0097b11c));
    void* type = fn_005ed5c0();
    fn_0056c650(self, 0, fn_0059c7f0(), type, a, b, flags);
    self->type = type;
    self->vtable = (unsigned)g_008402a4;
    Local_005eea70_Binding* bnd =
        reinterpret_cast<Local_005eea70_Binding*>(fn_006a0920(0xc));
    if (bnd) {
        bnd->vtable = (unsigned)g_0083fe40;
        bnd->getter = getter;
        bnd->setter = setter;
    }
    self->binding = bnd;
    return self;
}
