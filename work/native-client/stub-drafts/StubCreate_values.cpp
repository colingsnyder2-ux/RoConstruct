// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Creatable<Instance>::create<T>() for classes whose original create body was a `return 0` stub in our link
// (createfix.py: 00639a00 = create<Color3Value>, 00639900 = create<Vector3Value>; registry names were ICF-folded).
// Insert Object -> Creator<...>::create -> stub -> null deref. Both original bodies malloc 0x13c.
#include "util/Object.h"
#include "v8datamodel/Value.h"
typedef char roc_size_Color3Value[sizeof(RBX::Color3Value) == 0x13c ? 1 : -1];
typedef char roc_size_Vector3Value[sizeof(RBX::Vector3Value) == 0x13c ? 1 : -1];
template boost::shared_ptr<RBX::Color3Value> RBX::Creatable<RBX::Instance>::create<RBX::Color3Value>();
template boost::shared_ptr<RBX::Vector3Value> RBX::Creatable<RBX::Instance>::create<RBX::Vector3Value>();
