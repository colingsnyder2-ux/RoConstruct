// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"
#include <boost/shared_ptr.hpp>

namespace RBX {

// INFERRED: the disassembly calls the Clothing ctor (0x5d5700) and the
// shared_ptr<Script> ctor with Creatable<Instance>::Deleter (0x48f650).
// Both are most likely identical-code-folded with the Selection equivalents,
// so this uses the vendor form that builds a Selection.
// INFERRED: Instance.h is not at v8datamodel/Instance.h, so only Selection.h
// is included and it is assumed to pull in Instance and Creatable.
template<>
template<>
boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>()
{
    return boost::shared_ptr<Selection>(new Selection(), Deleter());
}

}
