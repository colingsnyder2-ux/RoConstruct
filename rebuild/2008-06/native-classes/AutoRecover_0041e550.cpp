// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h" // INFERRED: Instance.h lives under v8tree/, not v8datamodel/
#include "v8datamodel/Decal.h" // INFERRED: header that declares RBX::Texture

namespace RBX {

// INFERRED: explicit instantiation of the vendor template
// Creatable<Instance>::create<T>() { return boost::shared_ptr<T>(new T(), Deleter()); }
template boost::shared_ptr<Texture> Creatable<Instance>::create<Texture>();

}
