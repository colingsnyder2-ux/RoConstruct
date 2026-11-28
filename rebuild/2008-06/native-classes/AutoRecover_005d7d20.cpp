// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /U_RELEASEASSERT
#include "humanoid/Humanoid2008.h"

// INFERRED: The supplied verified analog is empty. This destructor body follows
// the native class layout, but its byte-exact code generation is unverified.
__forceinline RBX::Humanoid::~Humanoid()
{
}

extern "C" void __fastcall fn_005d7d20(RBX::Humanoid* self, int unusedEdx)
{
    self->RBX::Humanoid::~Humanoid();
}
