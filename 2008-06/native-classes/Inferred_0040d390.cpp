// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0040d390: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/Metadata.h"
#include "util/Name.h"

namespace RBX {

template boost::shared_ptr<Reflection::Metadata::Events> Creatable<Instance>::create<Reflection::Metadata::Events>();

}
