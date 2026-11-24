// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>

// INFERRED: derived std::exception subclass with no extra members; its dtor sets the vtable and tail-jumps to ~exception.
struct DerivedException : public std::exception {
    virtual ~DerivedException() {}
};

extern "C" void __fastcall fn_00568410(DerivedException* self, int unusedEdx)
{
    self->DerivedException::~DerivedException();
}
