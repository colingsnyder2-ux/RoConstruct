// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "script/Script.h"

// INFERRED: the header path "script/Script.h" is a guess.
// The previous attempt used an explicit instantiation of the member template
// constructor, which crashed the compiler (C1001). This version instead forces an
// implicit instantiation by constructing the shared_ptr from a non-inlined helper.
// The constructor builds the shared_count (call to 0x456410) and then runs the
// enable_shared_from_this hookup (weak_this at Script+0xe4).
// INFERRED: the out-of-line symbol is only emitted if the compiler does not inline
// the constructor into the helper below; I have not confirmed that it stays out of line.

__declspec(noinline) boost::shared_ptr<RBX::Script> Local_00456f10_make(RBX::Script* s)
{
    boost::shared_ptr<RBX::Script> p(s, RBX::Creatable<RBX::Instance>::Deleter());
    return p;
}
