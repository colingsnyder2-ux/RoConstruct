// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"

// INFERRED: Vendor template body; disassembly labels for callees differ.
// INFERRED: Byte match and callee identity remain unverified.
template<>
template<>
boost::shared_ptr<RBX::Selection>
RBX::Creatable<RBX::Instance>::create<RBX::Selection>()
{
    return boost::shared_ptr<RBX::Selection>(new RBX::Selection(), Deleter());
}
