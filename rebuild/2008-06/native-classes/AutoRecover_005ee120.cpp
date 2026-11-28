// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083fd8c[];
extern "C" char g_00840034[];
extern "C" char g_0097b11c[];
// INFERRED: layout and helper roles taken from the byte-exact analog; types are guesses.

extern "C" void fn_00557330(void (*fn)(), long* flag);
extern "C" void* fn_005ed5c0();
extern "C" void* fn_0059c7f0();
extern "C" int fn_006a0920(int a1);

struct Local_005ee120;
extern "C" Local_005ee120* __fastcall fn_0056c650(Local_005ee120* self, int unusedEdx,
                                                   void* classDesc, void* type,
                                                   unsigned int a, unsigned int b,
                                                   unsigned int flags);

extern "C" void fn_005ed620();

struct Local_Binding_005ee120 {
    unsigned int vtable;
    unsigned int getter;
    unsigned int setter;
};

struct Local_005ee120 {
    unsigned int vtable;
    unsigned int data[5];
    void* descriptor;
    Local_Binding_005ee120* binding;
};

extern "C" Local_005ee120* __fastcall fn_005ee120(Local_005ee120* self, int unusedEdx,
                                                   unsigned int a, unsigned int b,
                                                   unsigned int getter, unsigned int setter,
                                                   unsigned int flags)
{
    fn_00557330(fn_005ed620, reinterpret_cast<long*>(g_0097b11c));
    void* type = fn_005ed5c0();
    void* cls = fn_0059c7f0();
    fn_0056c650(self, 0, cls, type, a, b, flags);
    self->descriptor = type;
    self->vtable = (unsigned)g_00840034;
    Local_Binding_005ee120* bind =
        reinterpret_cast<Local_Binding_005ee120*>(fn_006a0920(12));
    if (bind) {
        bind->vtable = (unsigned)g_0083fd8c;
        bind->getter = getter;
        bind->setter = setter;
    }
    self->binding = bind;
    return self;
}
