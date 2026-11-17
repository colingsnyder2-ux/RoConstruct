// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041ceb0 ?create@Creator@?$FactoryProduct@VDHTMLWindowService@@VInstance@RBX@@$1?sDHTMLWindowService@@3PADA@RBX@@UBE?AV?$shared_p: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only (definition as in AppUnit400_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<DHTMLWindowService, RBX::Instance, sDHTMLWindowService>::Creator::create() const;
