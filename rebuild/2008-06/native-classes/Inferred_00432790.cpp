// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00432790: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Accoutrement.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

template<>
template<>
boost::shared_ptr<Hat> __cdecl Creatable<Instance>::create<Hat>()
{
	return boost::shared_ptr<Hat>(new Hat(), Creatable<Instance>::Deleter());
}

}
