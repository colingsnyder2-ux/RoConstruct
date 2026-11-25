// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: layout and names follow the server-verified analog; Local_ types avoid clashing with real headers.
extern "C" void fn_00557330(void (*fn)(), void* flag);   // boost::call_once (cdecl)
extern "C" void fn_005ed620();
extern "C" void* fn_005ed5c0();
extern "C" void* fn_0059c7f0();
extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0056c650(void* self, int unusedEdx, void* owner, void* type,
                                       unsigned int a, unsigned int b, unsigned int flags);

struct Local_005edde0_Base {
    unsigned int vtable;
    unsigned int data[5];
    Local_005edde0_Base(void* owner, void* type, unsigned int a, unsigned int b, unsigned int flags)
    {
        fn_0056c650(this, 0, owner, type, a, b, flags);
    }
    // INFERRED: non-inline destructor forces the EH unwind state seen in the original.
    ~Local_005edde0_Base();
};

struct Local_005edde0_Enum : Local_005edde0_Base {
    void* descriptor;
    Local_005edde0_Enum(void* owner, void* type, unsigned int a, unsigned int b, unsigned int flags)
        : Local_005edde0_Base(owner, type, a, b, flags), descriptor(type)
    {
    }
};

struct Local_005edde0_Binding {
    unsigned int vtable;
    unsigned int getter;
    unsigned int setter;
    Local_005edde0_Binding(unsigned int g, unsigned int s)
        : vtable(0x83fd50), getter(g), setter(s)
    {
    }
};

struct Local_005edde0 : Local_005edde0_Enum {
    Local_005edde0_Binding* binding;

    Local_005edde0(unsigned int a, unsigned int b, unsigned int getter,
                   unsigned int setter, unsigned int flags)
        : Local_005edde0_Enum(fn_0059c7f0(),
                              (fn_00557330(fn_005ed620, (void*)0x97b11c), fn_005ed5c0()),
                              a, b, flags)
    {
        vtable = 0x83ff64;
        binding = new Local_005edde0_Binding(getter, setter);
    }
};

extern "C" Local_005edde0* __fastcall fn_005edde0(Local_005edde0* self, int unusedEdx,
                                                  unsigned int a1, unsigned int a2,
                                                  unsigned int a3, unsigned int a4,
                                                  unsigned int a5)
{
    return new (self) Local_005edde0(a1, a2, a3, a4, a5);
}
