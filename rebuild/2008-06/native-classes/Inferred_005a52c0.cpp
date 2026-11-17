// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 005a52c0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Stats.h"
#include "util/Name.h"

namespace RBX {
namespace Stats {

template<>
Item* Item::createChildItem<int>(const char* name, boost::function0<int> f)
{
	boost::shared_ptr<Instance> item = Creatable<Instance>::create<TypedStatsItem<int>, boost::function0<int> >(f);
	Instance* p = item.get();
	{
		std::string s(name);
		p->setName(s);
	}
	p->setParent(this);
	return static_cast<Item*>(p);
}

}
}
