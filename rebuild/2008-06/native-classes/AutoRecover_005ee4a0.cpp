// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

extern "C" int fn_006a0920(int a1);
extern "C" void __cdecl fn_00557330(void (*)(), void*);
extern "C" void __cdecl fn_005ed620();
extern "C" void* __cdecl fn_005ed5c0();
extern "C" void* __cdecl fn_0059c7f0();

struct Local_005ee4a0_Base;

extern "C" void __fastcall fn_0056c650(Local_005ee4a0_Base* self, int unusedEdx,
                                       void* cls, void* type,
                                       unsigned int a, unsigned int b,
                                       unsigned int flags);
// INFERRED: PropertyDescriptor destructor used for unwinding
extern "C" void __fastcall fn_0056c6b0(Local_005ee4a0_Base* self, int unusedEdx);

struct Local_005ee4a0_Base {
    unsigned int vtable;
    unsigned int data[5];
    Local_005ee4a0_Base(void* cls, void* type, unsigned int a, unsigned int b,
                        unsigned int flags)
    {
        fn_0056c650(this, 0, cls, type, a, b, flags);
    }
    ~Local_005ee4a0_Base()
    {
        fn_0056c6b0(this, 0);
    }
};

struct Local_005ee4a0_Enum : Local_005ee4a0_Base {
    void* descriptor;
    Local_005ee4a0_Enum(void* cls, void* type, unsigned int a, unsigned int b,
                        unsigned int flags)
        : Local_005ee4a0_Base(cls, type, a, b, flags), descriptor(type) {}
};

struct Local_005ee4a0_Binding {
    unsigned int vtable;
    unsigned int getter;
    unsigned int setter;
    Local_005ee4a0_Binding(unsigned int g, unsigned int s)
        : vtable(0x83fdc8), getter(g), setter(s) {}
};

struct Local_005ee4a0 : Local_005ee4a0_Enum {
    Local_005ee4a0_Binding* binding;
    Local_005ee4a0(unsigned int a, unsigned int b, unsigned int getter,
                   unsigned int setter, unsigned int flags)
        : Local_005ee4a0_Enum(
              fn_0059c7f0(),
              (fn_00557330(fn_005ed620, reinterpret_cast<void*>(0x97b11c)),
               fn_005ed5c0()),
              a, b, flags)
    {
        vtable = 0x840104;
        binding = new Local_005ee4a0_Binding(getter, setter);
    }
};

extern "C" Local_005ee4a0* __fastcall fn_005ee4a0(Local_005ee4a0* self, int unusedEdx,
                                                  unsigned int a1, unsigned int a2,
                                                  unsigned int a3, unsigned int a4,
                                                  unsigned int a5)
{
    // INFERRED: constructor; arg order per disassembly (a1, a2, getter, setter, a5)
    return new (self) Local_005ee4a0(a1, a2, a3, a4, a5);
}
