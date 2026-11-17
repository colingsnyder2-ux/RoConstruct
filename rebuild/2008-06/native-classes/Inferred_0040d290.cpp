// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0040d290: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

template<> template<>
boost::shared_ptr<DHTMLWindowService> Creatable<Instance>::create<DHTMLWindowService>()
{
	return boost::shared_ptr<DHTMLWindowService>(new DHTMLWindowService(), Deleter());
}

}
