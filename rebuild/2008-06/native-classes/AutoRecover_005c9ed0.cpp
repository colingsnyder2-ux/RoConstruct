// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "script/Script.h"

// INFERRED: the header path is a guess, since no class header excerpt was provided.
// INFERRED: the compiler error shows sScript is declared as an array in the header,
// so the template argument is passed as the decayed pointer (sScript), not &sScript.
// INFERRED: the body is empty. The vtable stores, the Described<Instance> classDescriptor call and the
// FactoryProduct base constructor all come from the implicit constructor expansion.
template<>
RBX::DescribedCreatable<RBX::Script, RBX::Instance, RBX::sScript>::DescribedCreatable()
{
}
