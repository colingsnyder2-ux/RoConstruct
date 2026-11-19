// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0048ea00: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Hopper.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

template<>
template<>
boost::shared_ptr<LegacyHopperService> __cdecl Creatable<Instance>::create<LegacyHopperService>()
{
	return boost::shared_ptr<LegacyHopperService>(new LegacyHopperService(), Creatable<Instance>::Deleter());
}

}
