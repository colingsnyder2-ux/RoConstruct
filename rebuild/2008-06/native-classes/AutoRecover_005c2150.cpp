// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"

namespace RBX {

// INFERRED: the vendor code is the header template Creatable<Instance>::create<T>(),
// which builds boost::shared_ptr<T>(new T(), Deleter()). The previous attempt
// failed because the explicit specialization syntax didn't match the declaration,
// so this uses an explicit instantiation instead. That emits the function from
// the header definition.
template boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>();

}
