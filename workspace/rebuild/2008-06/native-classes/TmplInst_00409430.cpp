// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00409430 ?create@Creator@?$FactoryProduct@VPlayer@Network@RBX@@VInstance@3@$1?sPlayer@23@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RB: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "Network/Player.h"
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
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>::Creator::create() const;
