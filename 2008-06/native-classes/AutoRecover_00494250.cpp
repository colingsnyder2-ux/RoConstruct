// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"

// INFERRED: Creatable<Instance>::create<T>() is defined generically in the header as
// shared_ptr<T>(new T(), Deleter()). An explicit instantiation emits the 2008 code for T = Selection.
template boost::shared_ptr<RBX::Selection> RBX::Creatable<RBX::Instance>::create<RBX::Selection>();
