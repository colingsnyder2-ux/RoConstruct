// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "script/Script.h"

// The target is boost's own template constructor
//   boost::shared_ptr<RBX::Script>::shared_ptr<RBX::Script, RBX::Creatable<RBX::Instance>::Deleter>(Script*, Deleter)
// instantiated in App/script/Script.cpp. Its body (from boost/shared_ptr.hpp) is:
//   px(p), pn(p, d)                       -> shared_count ctor (fn_005b75a0 in the disassembly)
//   sp_enable_shared_from_this(pn, p, p)  -> sets the weak_ptr at Script+0xE4 (px at +0, pn at +4)
// The constructor cannot be redefined here, so the file only forces its instantiation.
//
// INFERRED: header path "script/Script.h" is a guess; no class header excerpt was provided.
// INFERRED: Script derives from enable_shared_from_this. That explains the weak_ptr assignment
// at offset 0xE4.
// INFERRED: an explicit instantiation crashed the compiler (C1001). The constructor is therefore
// instantiated implicitly through a non-inlined wrapper with external linkage. With inlining
// disabled, the out-of-line constructor body is emitted.

#pragma inline_depth(0)

__declspec(noinline) boost::shared_ptr<RBX::Script> RBX_Script_instantiateSharedPtrDeleterCtor(RBX::Script* p)
{
    return boost::shared_ptr<RBX::Script>(p, RBX::Creatable<RBX::Instance>::Deleter());
}

#pragma inline_depth()
