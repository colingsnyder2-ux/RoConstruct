// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"

// INFERRED: Instantiate the vendor implementation already defined in Object.h.
template boost::shared_ptr<RBX::Selection>
RBX::Creatable<RBX::Instance>::create<RBX::Selection>();
