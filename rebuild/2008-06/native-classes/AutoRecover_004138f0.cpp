// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080e960[];   // INFERRED: unnamed global at 0x0080e960 in the original
#include <new>

// INFERRED: no CopyVerb / EditSelectionVerb header was available, so the
// compiler-generated vector deleting destructor is written out by hand
// with a file-local object type.
struct Local_004138f0 {
    void* vtable;
};

// RBX::EditSelectionVerb::~EditSelectionVerb (thiscall)
extern "C" void __fastcall fn_0057e050(Local_004138f0* self, int unusedEdx);

extern "C" Local_004138f0* __fastcall fn_004138f0(Local_004138f0* self, int unusedEdx, unsigned int flags)
{
    // INFERRED: ((int)&g_0080e960) is the CopyVerb vtable address
    self->vtable = (void*)((int)&g_0080e960);
    // pass the incoming edx through so the compiler emits no edx setup
    fn_0057e050(self, unusedEdx);
    if (flags & 1) {
        ::operator delete((void*)self);
    }
    return self;
}
