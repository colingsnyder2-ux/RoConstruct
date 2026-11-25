// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided, so the types below are minimal
// stand-ins that reproduce the member offsets seen in the disassembly.

struct ClassDescriptor;

struct AccessorImpl {            // 0x18-byte object allocated by fn_006a0920
    void*       vtbl;            // +0x00
    void*       owner;           // +0x04
    int         a3;              // +0x08
    int         pad0c;           // +0x0c (never written here)
    int         a4;              // +0x10
    int         a5;              // +0x14
};

struct SoundFloatProp {          // derived from TypedPropertyDescriptor<float>
    void*         vtbl;          // +0x00
    char          base[0x14];    // +0x04 .. +0x17 (base-class members)
    AccessorImpl* accessor;      // +0x18
};

// INFERRED: null auto_ptr passed by value to the base constructor.
// Its destructor gives the temporary's EH unwind states in the original.
struct NullAutoPtr {
    void* p;
    NullAutoPtr() : p(0) {}
    ~NullAutoPtr() { if (p) ::operator delete(p); }
};

// INFERRED: vtables of the derived property descriptor and its accessor impl.
extern "C" char g_00824134[];
extern "C" char g_0083760c[];

extern "C" int fn_006a0920(int a1);                      // operator new
extern "C" ClassDescriptor* fn_005bb7f0();               // Described<SoundService,...>::classDescriptor
extern "C" void __fastcall fn_00445610(void* self, int unusedEdx,
                                       ClassDescriptor* desc, const char* name,
                                       const char* category, NullAutoPtr getter,
                                       int arg6);

extern "C" SoundFloatProp* __fastcall fn_005bb940(SoundFloatProp* self, int unusedEdx,
                                                  const char* arg1, const char* arg2,
                                                  int arg3, int arg4, int arg5, int arg6)
{
    fn_00445610(self, 0, fn_005bb7f0(), arg1, arg2, NullAutoPtr(), arg6);
    self->vtbl = (void*)g_00824134;

    AccessorImpl* impl = (AccessorImpl*)fn_006a0920(0x18);
    if (impl) {
        impl->vtbl  = (void*)g_0083760c;
        impl->owner = self;
        impl->a3    = arg3;
        impl->a4    = arg4;
        impl->a5    = arg5;
    }

    AccessorImpl* old = self->accessor;
    if (impl != old && old)
        ::operator delete(old);
    self->accessor = impl;
    return self;
}
