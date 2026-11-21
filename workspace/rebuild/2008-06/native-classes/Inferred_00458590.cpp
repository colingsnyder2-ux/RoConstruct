// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00458590: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/Metadata.h"
#include "util/Name.h"

namespace RBX {

template<>
template<>
boost::shared_ptr<Reflection::Metadata::Properties> Creatable<Instance>::create<Reflection::Metadata::Properties>()
{
	return boost::shared_ptr<Reflection::Metadata::Properties>(new Reflection::Metadata::Properties(), Deleter());
}

}
