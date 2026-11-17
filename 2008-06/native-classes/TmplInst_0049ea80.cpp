// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0049ea80 ?create@Creator@?$FactoryProduct@VNetworkSettings@RBX@@VItem@GlobalSettings@2@$1?sNetworkSettings@2@3PADA@RBX@@UBE?AV?$s: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "NetworkSettings.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::NetworkSettings, RBX::GlobalSettings::Item, RBX::sNetworkSettings>::Creator::create() const;
