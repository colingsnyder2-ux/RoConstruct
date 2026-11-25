// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083fe54[];   // INFERRED: unnamed global at 0x0083fe54 in the original
extern "C" char g_008402f4[];   // INFERRED: unnamed global at 0x008402f4 in the original
extern "C" char g_0097b120[];   // INFERRED: unnamed global at 0x0097b120 in the original
#include <new>
// INFERRED: structure follows the server-verified analog. Base has a non-trivial destructor, which gives the EH frame.
typedef unsigned int size_t;

extern "C" int fn_006a0920(int a1);
extern "C" void __cdecl fn_00557330(void (__cdecl *once)(), void* flag);
extern "C" void __cdecl fn_005ed690();
extern "C" void* __cdecl fn_005ed630();
extern "C" void* __cdecl fn_0059c7f0();
extern "C" void __fastcall fn_0056c650(void* self, int unusedEdx, void* classDesc, void* type,
                                       unsigned int a1, unsigned int a2, unsigned int a5);

struct Local_005eeb20_Base {
    unsigned int vtable;
    unsigned int data[5];

    Local_005eeb20_Base(void* owner, void* type, unsigned int a, unsigned int b, unsigned int flags)
    {
        fn_0056c650(this, 0, owner, type, a, b, flags);
    }
    ~Local_005eeb20_Base();
};

struct Local_005eeb20_Enum : Local_005eeb20_Base {
    void* descriptor;

    Local_005eeb20_Enum(void* owner, void* type, unsigned int a, unsigned int b, unsigned int flags)
        : Local_005eeb20_Base(owner, type, a, b, flags), descriptor(type)
    {
    }
};

struct Local_005eeb20_Binding {
    unsigned int vtable;
    unsigned int getter;
    unsigned int setter;

    static void* operator new(size_t n) { return (void*)fn_006a0920((int)n); }

    Local_005eeb20_Binding(unsigned int g, unsigned int s)
        : vtable(((int)&g_0083fe54)), getter(g), setter(s)
    {
    }
};

struct Local_005eeb20 : Local_005eeb20_Enum {
    Local_005eeb20_Binding* binding;

    Local_005eeb20(unsigned int a, unsigned int b, unsigned int getter,
                   unsigned int setter, unsigned int flags)
        : Local_005eeb20_Enum(fn_0059c7f0(),
                              (fn_00557330(fn_005ed690, reinterpret_cast<void*>(((int)&g_0097b120))),
                               fn_005ed630()),
                              a, b, flags)
    {
        vtable = ((int)&g_008402f4);
        binding = new Local_005eeb20_Binding(getter, setter);
    }
};

extern "C" Local_005eeb20* __fastcall fn_005eeb20(Local_005eeb20* self, int unusedEdx,
                                                  unsigned int a1, unsigned int a2,
                                                  unsigned int a3, unsigned int a4,
                                                  unsigned int a5)
{
    return new (self) Local_005eeb20(a1, a2, a3, a4, a5);
}

inline void* operator new(size_t, void* p) { return p; }
